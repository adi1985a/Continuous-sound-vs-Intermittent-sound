# 🎵🔊 VCL AudioPlayer Demo: MediaPlayer vs. sndPlaySound 🎶
_A Borland C++ Builder VCL application demonstrating synchronous and asynchronous audio playback using MediaPlayer and sndPlaySound API._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++ Builder](https://img.shields.io/badge/Framework-Borland%20C%2B%2B%20Builder%20VCL-orange.svg)](https://www.embarcadero.com/products/cbuilder) <!-- Or link to legacy Borland if more appropriate -->
[![Platform: Windows](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)

## 📋 Table of Contents
1.  [Overview](#-overview)
2.  [Key Features & Playback Methods](#-key-features--playback-methods)
3.  [Screenshots (Conceptual)](#-screenshots-conceptual)
4.  [System Requirements](#-system-requirements)
5.  [Project Setup in Borland C++ Builder](#️-project-setup-in-borland-c-builder)
6.  [Usage Guide](#️-usage-guide)
7.  [File Structure](#-file-structure)
8.  [Technical Notes](#-technical-notes)
9.  [Contributing](#-contributing)
10. [License](#-license)
11. [Contact](#-contact)

## 📄 Overview

**VCL AudioPlayer Demo**, developed by Adrian Lesniak, is a C++ application built using Borland C++ Builder and its Visual Component Library (VCL). This program serves as a practical demonstration of two distinct methods for playing audio files on Windows:
1.  **Synchronous Playback**: Utilizing the `TMediaPlayer` VCL component.
2.  **Asynchronous Playback**: Employing the WinAPI function `sndPlaySound` from `mmsystem.h`.
The application features a simple graphical user interface (GUI) with dedicated buttons to trigger each playback method. It also handles the loading of the audio file (`snd/dzwiek.wav`) upon form creation and ensures proper resource cleanup when the form is closed.

<p align="center">
  <img src="screenshots\1.jpg" width="300"/>
</p>

## ✨ Key Features & Playback Methods

*   <0xF0><0x9F><0xAA><0xBD> **MediaPlayer Playback (Synchronous)**:
    *   Triggered by `Button1`.
    *   Uses `MediaPlayer1->Play()` to start playback.
    *   The audio file plays to completion, and subsequent clicks on the button during playback typically have no effect until the current playback finishes (behavior characteristic of synchronous or managed playback).
*   🔊 **`sndPlaySound` Playback (Asynchronous by Default)**:
    *   Triggered by `Button2`.
    *   Uses the `sndPlaySound` function with the `SND_ASYNC` flag.
    *   Playback starts immediately and can be interrupted/restarted by subsequent clicks on the button. The application continues to respond during playback.
    *   *(Note: The description mentions an optional `SND_SYNC` mode, which would make `sndPlaySound` behave synchronously, queuing clicks for sequential playback if the sound isn't already playing.)*
*   🖥️ **VCL Graphical User Interface (GUI)**:
    *   A main form (`TForm`) hosts the interactive elements.
    *   `Button1`: Labeled for MediaPlayer playback.
    *   `Button2`: Labeled for `sndPlaySound` playback.
*   ⚙️ **Form Event Handling**:
    *   `FormCreate`: Automatically loads and opens the specified audio file (`snd/dzwiek.wav`) for the `TMediaPlayer` component when the application starts.
    *   `FormClose`: Properly closes the `TMediaPlayer` component to release associated system resources when the application window is closed.
*   🎵 **Audio File Dependency**:
    *   The application is hardcoded to look for an audio file named `dzwiek.wav` located in a subfolder named `snd` (i.e., `snd/dzwiek.wav`) relative to the executable's path.

## ⚙️ System Requirements

*   **Development Environment**: Borland C++ Builder (specific version compatible with the VCL components and project files used).
*   **Operating System**: Windows (due to heavy reliance on VCL, `mmsystem.h`, and `sndPlaySound` WinAPI).
*   **Required Libraries/Headers**:
    *   `<vcl.h>` (Borland VCL core)
    *   `<mmsystem.h>` (Windows Multimedia API for `sndPlaySound`)
    *   `<iostream>` (if used for any console debugging, though primarily a GUI app)
*   **Local Asset**: The audio file `snd/dzwiek.wav` must be present in the correct subfolder.

## 🛠️ Project Setup in Borland C++ Builder

1.  **Clone or Obtain Project Files**:
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```
    *(Replace `<repository-url>` and `<repository-directory>` if applicable, or simply ensure all project files are in a single directory.)*

2.  **Prepare Audio Asset**:
    *   Create a subfolder named `snd` within your project's main directory (or where the final executable will reside).
    *   Place the audio file `dzwiek.wav` inside this `snd` subfolder.

3.  **Project Files**:
    *   **`Unit1.cpp`**: This file should contain the C++ source code with the event handler implementations for `FormCreate`, `FormClose`, `Button1Click`, and `Button2Click`.
    *   **`Unit1.dfm`**: This is the Borland VCL form file that defines the GUI layout and component properties (e.g., `TMediaPlayer` named `MediaPlayer1`, `TButton` named `Button1`, `TButton` named `Button2`). This file is typically managed by the C++ Builder IDE's Form Designer. Ensure it contains:
        *   A `TMediaPlayer` component (e.g., named `MediaPlayer1`).
        *   Two `TButton` components (e.g., named `Button1` and `Button2`).
        *   The `OnClick` events for the buttons and the `OnCreate` and `OnClose` events for the form must be linked to their respective C++ handler functions in `Unit1.cpp`.

4.  **Open and Compile in Borland C++ Builder**:
    *   Open the project file (e.g., `*.bpr` or `*.cbproj` depending on the C++ Builder version) in the Borland C++ Builder IDE.
    *   Use the IDE’s "Build" or "Make" command to compile the project.
    *   Use the IDE's "Run" command to execute the application.

    *Alternatively, if compiling manually (less common for VCL projects without a makefile):*
    ```bash
    bcc32 Unit1.cpp # This is a simplified example and might require linking VCL libraries.
    ```
    *Manual compilation of VCL applications is complex and typically handled by the IDE's build system.*

## 💡 Usage Guide

1.  Build and run the application from within the Borland C++ Builder IDE or by executing the compiled `.exe` file (ensure `snd/dzwiek.wav` is correctly placed).
2.  **Interface**:
    *   A simple window will appear, containing two buttons (e.g., "Play with MediaPlayer" and "Play with sndPlaySound").
3.  **Actions**:
    *   **Click Button1 (MediaPlayer)**: The audio file `dzwiek.wav` will begin playing. It will play to completion. Clicking this button again while the sound is playing will likely have no immediate effect on the ongoing playback.
    *   **Click Button2 (`sndPlaySound`)**: The audio file `dzwiek.wav` will begin playing asynchronously. If you click this button again while the sound is playing, the sound will typically restart from the beginning.
4.  **Close the Form**:
    *   Closing the application window will trigger the `FormClose` event, which should properly release resources used by `MediaPlayer1`.

## 🗂️ File Structure

*   `Unit1.cpp`: The main C++ source file containing the implementation for the form's event handlers and logic.
*   `Unit1.h`: (Implicitly generated by C++ Builder) The header file for `Unit1.cpp`, declaring the form class and its components.
*   `Unit1.dfm`: The Borland VCL form file, defining the GUI layout and properties of components. This is typically edited visually in the IDE.
*   `snd/dzwiek.wav`: The audio file required for playback.
*   `[ProjectName].bpr` or `[ProjectName].cbproj`: The Borland C++ Builder project file.
*   `README.md`: This documentation file.

## 📝 Technical Notes

*   **Windows-Specific**: This application is fundamentally Windows-specific due to its reliance on the Borland VCL framework and the Windows Multimedia API (`mmsystem.h` for `sndPlaySound`). Adapting it for other platforms would require a complete rewrite using a cross-platform GUI toolkit and audio library.
*   **Component Configuration**: The correct functioning of the application heavily depends on the `Unit1.dfm` file having the `TMediaPlayer` (named `MediaPlayer1`) and `TButton` components correctly placed and their events linked to the handlers in `Unit1.cpp`.
*   **Audio File Path**: The path `ExtractFilePath(Application->ExeName) + "snd\\dzwiek.wav"` is used to locate the audio file. This ensures it looks for the `snd` folder in the same directory as the executable.
*   **Error Handling**: The provided code snippet focuses on playback. Robust error handling (e.g., checking if `dzwiek.wav` exists and can be opened, handling `sndPlaySound` return values) would be important in a production application.
*   **Comments**: The original code description mentions Polish comments. While the functionality is described in English, the source code itself might contain comments in Polish.

## 🤝 Contributing

Contributions to this **VCL AudioPlayer Demo** are welcome, especially if they aim to improve error handling, add more playback features, or provide clearer examples of using VCL audio components.

1.  Fork the repository.
2.  Create a new branch for your feature (`git checkout -b feature/AudioEnhancement`).
3.  Make your changes (primarily to `Unit1.cpp` and potentially `Unit1.dfm` via the IDE).
4.  Commit your changes (`git commit -m 'Feature: Add AudioEnhancement'`).
5.  Push to the branch (`git push origin feature/AudioEnhancement`).
6.  Open a Pull Request.

Please ensure your code is well-commented and follows good C++ Builder and VCL practices.

## 📃 License

This project is licensed under the **MIT License**.
(If you have a `LICENSE` file in your repository, refer to it: `See the LICENSE file for details.`)

## 📧 Contact

Created by **Adrian Lesniak**.
For questions or feedback regarding this VCL audio demo, please open an issue on the GitHub repository or contact the repository owner.

---
🎤 _Demonstrating diverse audio playback techniques in the Borland C++ Builder VCL environment._
