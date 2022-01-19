
<br />
<div align="center">
  <a href="https://github.com/Jax-Core/MIUI-Shade">
    <img src="" alt="Logo" width="200" height="200">
  </a>

<h3 align="center">MIUI-Shade</h3>





  <p align="center">
    A PC-based version of an Android control center.
    <br />
    <a href="https://www.deviantart.com/jaxoriginals/art/MIUI-Shade-v2-0-885183361"><strong>More Info »</strong></a>
    <br />
    <br />
    <a href="https://discord.gg/JmgehPSDD6">Report Bugs & Request Features </a>
  </p>
</div>


<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about">About</a>
    </li>
    <li>
      <a href="#Features">Features</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
         <li> <a href="#custom-color-schemes">Custom Color Schemes</a></li>
      </ul>
    </li>
    <li>
    <a href="#modules-setup">Modules Setup</a>
    <ul>
         <li><a href="#media-controls">Media Controls</a>
          <ul>
            <li><a href="#for-spotify">Spotify</a></li>
            <li><a href="#for-web-players">Web Players</a></li>
          </ul>
        </li>
        <li><a href="#weather">Weather</a></li>
      </ul>
    </li>
    <li> <a href="#help-and-credits">Help & Credits</a></li>

  </ol>
</details>


## About

https://user-images.githubusercontent.com/97158976/150152881-dbcae5c4-a1d4-4e2e-9310-985feb31d3b9.mp4

MIUI-Shade is a Rainmeter skin that brings the Android control center to Windows. MIUI-Shade includes 2 different color schemes as well as multiple customization options for you to tweak and customize to your liking. **See the video linked above.**

## Features

* Flawless Animations
* Full-fledged Control Center
* Intergrated Media Controls
* Customizable Hotkeys
* Additional Modules like Weather Status

## Getting Started

### Prerequisites

- **Rainmeter v4.5 or newer.** Rainmeter can be installed by downloading the `.exe` file [from Rainmeter's official website.](https://www.rainmeter.net/)
- **JaxCore v40005 or newer.** JaxCore can be installed by downloading the `.rmskin` file from [JaxCore's official website.](https://jax-core.github.io/)

### Installation

Assuming you successfully downloaded and installed Rainmeter as well as JaxCore, you can now proceed to install MIUI-Shade by following the steps below.

1. Download and run the `.rmskin` file for **MIUI-Shade** from the official [JaxCore site](https://jax-core.github.io/) to install **MIUI-Shade**.
2. Leave the installation settings at their defaults and click Install.
3. When the installation is finished, a startup pop-up should appear. Follow through the pop-up to finish installing MIUI-Shade.

* Note:  If you find that the JaxCore option is red on the startup pop-up, please press the red button and Core will be installed automatically. Perchance this fails, you can manually install Core by downloading the `.rmskin` file from [JaxCore's official website.](https://jax-core.github.io/)

### Customization

MIUI-Shade includes 2 color scheme presets. You enable them by just selecting them within the **Appearance** tab. These are their names:

- Dark
- Light

And, the blur preset types are:
- Blur
- Acrylic

You can also change the skin scale and animations within the same **Appearance** tab.

## Modules Setup

Now that you've installed and setup MIUI-Shade, let's begin setting up some modules it comes with!

### Media Controls

#### For Spotify:
For media controls to work with Spotify, you will have to setup and install **[Spicetify](https://spicetify.app/).** Follow the steps below to do so.

1. Open Powershell (Windows 10) or Windows Terminal (Windows 11) and run the commands that follow:
    ```
      Invoke-WebRequest -UseBasicParsing "https://raw.githubusercontent.com/khanhas/spicetify-cli/master/install.ps1" | Invoke-Expression

      spicetify

      spicetify config extensions webnowplaying.js
    ```
   **If you only want to install `webnowplaying.js` without the custom themes, use the following command:**
      ```
        spicetify config inject_css 0 replace_colors 0
      ```
2. And finally, run the following command to save and apply all your changes:
    ```
      spicetify backup apply
    ```

You can now proceed to configure media controls for Spotify. Simply follow the steps outlined below:

1. Open Core and head over to the **Modules** section.
2. Select **MIUI-Shade** from the list and proceed to the **Modules** tab.
3. In the **Media** tab select **Spotify**.
4. Ignore the alert for Spicetify(we've already installed this in the previous step) and press **confirm** on the bottom right.
5. Refresh MIUI-Shade and your media controls for Spotify should work.

#### For Web Players:
For media controls to work with any website, you will have to install the **[WebNowPlaying Companion](https://chrome.google.com/webstore/detail/webnowplaying-companion/jfakgfcdgpghbbefmdfjkbdlibjgnbli) extension for your browser.** 

Once you've installed the extension, you can now proceed to configure media controls for Web Players. Simply follow the steps outlined below:

1. Open Core and head over to the **Modules** section.
2. Select **MIUI-Shade** from the list and proceed to the **Media** tab.
3. In the **Media** tab select **Web**.
4. Ignore the alert for WebNowPlaying Companion extension(we've already installed this in the previous step) and press **confirm** on the bottom right.
5. Refresh MIUI-Shade and your media controls for any website should work.


### Weather

Weather Status, unlike Media Controls, does not require the installation of any additional applications or extensions. As a result, you can simply enable it via the **General** tab. To do so, follow the steps outlined below.

1. Open Core and head over to the **Modules** section.
2. Select **MIUI-Shade** from the list and proceed to the **General** tab.
3. Under **Time & Weather**, change `Weather Location` to the location you want the weather status for.
4. Refresh MIUI-Shade and your weather status should work.


## Help and Credits
- Spicetify by [khanhas](https://github.com/khanhas).
- Join the [Core Community Discord Server](https://discord.gg/JmgehPSDD6) for more help.
