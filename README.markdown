# Audio Playback Program

## Overview
This C++ VCL application, built with Borland C++ Builder, plays audio files using two methods: MediaPlayer for synchronous playback (plays fully) and `sndPlaySound` for asynchronous playback (restarts on click). It features a GUI with buttons to trigger playback, loads audio on form creation, and cleans up on form close.

## Features
- **MediaPlayer Playback**:
  - Synchronous playback via `MediaPlayer1->Play()`.
  - Plays audio file fully, unaffected by additional clicks.
- **sndPlaySound Playback**:
  - Asynchronous playback using `sndPlaySound` with `SND_ASYNC`.
  - Restarts audio on each button click.
  - Optional synchronous mode (`SND_SYNC`) queues clicks for sequential playback.
- **GUI Components**:
  - `Button1`: Triggers MediaPlayer playback.
  - `Button2`: Triggers `sndPlaySound` asynchronous playback.
- **Form Events**:
  - `FormCreate`: Loads and opens audio file (`snd/dzwiek.wav`).
  - `FormClose`: Closes MediaPlayer to free resources.
- **Audio File**:
  - Expects `snd/dzwiek.wav` in the `snd` subfolder.

## Requirements
- Borland C++ Builder (for VCL and `vcl.h`)
- Windows OS (for `mmsystem.h` and `sndPlaySound`)
- Libraries: `<vcl.h>`, `<mmsystem.h>`, `<iostream>`
- Local asset: `snd/dzwiek.wav` (audio file in `snd` subfolder)
- Operating system: Windows (due to VCL and `mmsystem.h`)

## Setup
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```
2. Ensure `snd/dzwiek.wav` is in the `snd` subfolder relative to the executable.
3. Save the provided code as `Unit1.cpp`.
4. Create or ensure the form file (`Unit1.dfm`) exists with:
   - `MediaPlayer1` component
   - `Button1` and `Button2` components
   - Event handlers linked to `Button1Click`, `Button2Click`, `FormCreate`, and `FormClose`
5. Open the project in Borland C++ Builder.
6. Compile and run the project:
   - Use the IDE’s build and run commands.
   - Alternatively, compile manually if supported:
     ```bash
     bcc32 Unit1.cpp
     ```

## Usage
1. Build and run the program in Borland C++ Builder.
2. **Interface**:
   - A form with two buttons: one for MediaPlayer, one for `sndPlaySound`.
3. **Actions**:
   - Click `Button1`: Plays `dzwiek.wav` fully using MediaPlayer (synchronous).
   - Click `Button2`: Plays `dzwiek.wav` asynchronously using `sndPlaySound`; restarts on each click.
   - Close the form: Cleans up MediaPlayer resources.
4. **Output**:
   - Audio playback of `dzwiek.wav` based on the selected method.
   - Asynchronous mode restarts audio; synchronous mode completes playback.

## File Structure
- `Unit1.cpp`: Main C++ source file with form logic and event handlers.
- `Unit1.dfm`: VCL form file defining the GUI (assumed, not provided).
- `snd/dzwiek.wav`: Audio file for playback.
- `README.md`: This file, providing project documentation.

## Notes
- Windows-specific due to VCL and `mmsystem.h`; adapt for other platforms by replacing `sndPlaySound`.
- Requires `Unit1.dfm` with properly configured components (MediaPlayer, buttons).
- Audio file path (`snd/dzwiek.wav`) is hardcoded; update if moved.
- Extend by adding more audio files, a file selector, or playback controls (pause, stop).
- No input validation; assumes `dzwiek.wav` exists.
- Uses Polish comments but English for file paths and functionality.

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make changes and commit (`git commit -m "Add feature"`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact
For questions or feedback, open an issue on GitHub or contact the repository owner.