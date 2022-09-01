<style>
	.image {
		max-width:640px;
		max-heigth:480px;
		border-radius:20px
	}
</style>

<a name="readme-top"></a>

[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

# M5Stack-Core2-Love-Globe

A small application that turns a M5Stack Core2 into a digital Love Globe.

<img class="image" src="/assets/images/love-globe.gif" width="640" height="480" />
<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- PREREQUISITES -->
## Prerequisites

This project use the VS Code Plugin `PlatformIO` as Development IDE.

<!-- TECHNICALS -->
## Technicals

### Image formats

__RGB565__:

To convert a PNG image to RGB565, the three bytes for RGB are converted to two 
bytes. The red component is reduced to 5 bits, the green component to 6 bits and
the blue component to 5 bits, so that the three RGB bytes are converted into two 
bytes.


__XBM__:

XBM is a monochrome bitmap format that stores data as a data array. It is mainly 
used to store cursor and icon bitmaps for use in graphical user interfaces.

Images can be converted to XBM format using the online converter here:

https://www.online-utility.org/image/convert/to/XBM

The output must be placed in a header file, renamed, and adjusted to appear as 
a constant UINT8 array in PROGMEM (FLASH program memory).

<!-- CONTACT -->
## Contact

Konrad Hauke - [@K0NRADhauke](https://twitter.com/K0NRADhauke) - hauke.konrad@gmail.com

Project Link: [https://github.com/K0NRAD/M5Stack-Core2-Love-Globe](https://github.com/K0NRAD/M5Stack-Core2-Love-Globe)

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, 
inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a 
pull request. You can also simply open an issue with the tag "enhancement".

Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'feat:Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

Please use **Conventional Commits** messages. Details about Conventional Commits
find youn on [https://www.conventionalcommits.org](https://www.conventionalcommits.org/en/v1.0.0/)

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- MARKDOWN LINKS & IMAGES -->
[contributors-shield]: https://img.shields.io/github/contributors/K0NRAD/M5Stack-Core2-Love-Globe.svg?style=for-the-badge
[contributors-url]: https://github.com/K0NRAD/M5Stack-Core2-Love-Globe/graphs/contributors
[forks-shield]:     https://img.shields.io/github/forks/K0NRAD/M5Stack-Core2-Love-Globe.svg?style=for-the-badge
[forks-url]:        https://github.com/K0NRAD/M5Stack-Core2-Love-Globe/network/members
[stars-shield]:     https://img.shields.io/github/stars/K0NRAD/M5Stack-Core2-Love-Globe.svg?style=for-the-badge
[stars-url]:        https://github.com/K0NRAD/M5Stack-Core2-Love-Globe/stargazers
[issues-shield]:    https://img.shields.io/github/issues/K0NRAD/M5Stack-Core2-Love-Globe.svg?style=for-the-badge
[issues-url]:       https://github.com/K0NRAD/M5Stack-Core2-Love-Globe/issues
[license-shield]:   https://img.shields.io/github/license/K0NRAD/M5Stack-Core2-Love-Globe.svg?style=for-the-badge
[license-url]:      https://github.com/K0NRAD/M5Stack-Core2-Love-Globe/blob/master/LICENSE.txt
[linkedin-shield]:  https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]:     https://linkedin.com/in/linkedin_username
[product-screenshot]: images/screenshot.png
