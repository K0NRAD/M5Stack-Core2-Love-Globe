from PIL import Image
import re


class Img2RGB565():
    def __init__(self, image_path, include_path, image_name=None, swap=False):
        self.include_path = include_path
        self.image_path = image_path
        self.image_name = image_name if image_name else "image"
        self.swap = swap

    def load_image(self):
        try:
            with Image.open(self.image_path) as image:
                self.pixels = image.load()
                self.image_width = image.size[0]
                self.image_height = image.size[1]

        except Exception as ex:
            print(f'failed to load image file: {self.image_path}', ex)

    def convert(self):
        self.load_image()
        try:
            with open(self.include_path, "w") as file:
                print(f"#include <stdint.h>", file=file)
                print(f"#include <pgmspace.h>\n", file=file)

                image_name = "_".join(re.findall('[a-zA-Z][^A-Z]*', self.image_name))

                print(f"#define {image_name.upper()}_WIDTH  {self.image_width}", file=file)
                print(f"#define {image_name.upper()}_HEIGHT {self.image_height}\n", file=file)

                print(f"PROGMEM const static uint16_t {self.image_name}[] = {{", file=file)

                for y in range(self.image_height):
                    for x in range(self.image_width):
                        if (y * 16 + x) % 16 == 0:
                            print("\n\t", file=file, end='')

                        r = self.pixels[x, y][0] >> 3
                        g = self.pixels[x, y][1] >> 2
                        b = self.pixels[x, y][2] >> 3

                        rgb = (r << 11) | (r << 5) | b

                        if self.swap:
                            rgb_low_byte = rgb >> 8
                            rgb_high_byte = (rgb & 0x00FF) << 8
                            rgb = rgb_low_byte | rgb_high_byte

                        print(f"0x{rgb:04x},", file=file, end='')

                print("\n};", file=file)
        except Exception as ex:
            print(f"failed to write include file: {self.include_path}", ex)

        print(f"image file {self.image_path} is converted to {self.include_path}")


def main():
    import argparse

    parser = argparse.ArgumentParser()

    parser.add_argument("-img", "--image-path", type=str, required=True, help="Path to the image file")
    parser.add_argument("-inc", "--include-path", required=True, help="Path to the include file")
    parser.add_argument("-iname", "--image-name", help="Name of image array")
    parser.add_argument("-s", "--swap", default=False, action="store_true", help="Swap RGB byte order")

    args = parser.parse_args()

    img_2_rgb565 = Img2RGB565(args.image_path, args.include_path, args.image_name, args.swap)
    img_2_rgb565.convert()


if __name__ == "__main__":
    main()
