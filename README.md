# ESP-SHARP Android — GitHub Actions build

This repository builds the ESP-SHARP Android app automatically on GitHub Actions.

## Build on GitHub

1. Create a new GitHub repository.
2. Upload the **contents of this folder** to the repository root. The `app` folder must be directly in the repository root.
3. Open **Actions** → **Build ESP-SHARP APK**.
4. If the workflow is not running automatically, choose **Run workflow**.
5. Open the completed workflow run.
6. Under **Artifacts**, download `ESP-SHARP-debug-apk`.
7. Inside the downloaded artifact is `app-debug.apk`.

The build uses Java 8, Android SDK 35, and Gradle 6.1.1 to match the existing project.

## Important

- No OpenAI API key is included in the source or APK build configuration.
- The GitHub Actions workflow does not require AndroidIDE or a local `/usr/bin/aapt2`.
