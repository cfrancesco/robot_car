# Installation of command line tools
Install `arduino-cli`


# Compile and upload project
From the root folder of the project, run the following commands:
```bash
arduino-cli compile --fqbn arduino:avr:uno .
arduino-cli upload --port /dev/tty.usbmodem1101 --fqbn arduino:avr:uno .
```

To use a different folder for the build files, use the `--output-dir` and `input-dir` flags
```bash
arduino-cli compile --fqbn arduino:avr:uno . --output-dir build
arduino-cli upload --port /dev/tty.usbmodem1101 --fqbn arduino:avr:uno .  --input-dir build
```

## Useful resources
Use `arduino-cli`: [tutorial](https://www.devdungeon.com/content/arduino-cli-tutorial)
### arcuino-cli useful commands
#### list boards and ports
```bash
arduino-cli board list
```
#### compile
```bash
arduino-cli compile --fqbn arduino:avr:uno file.ino
```
#### upload
```bash
arduino-cli upload --port /dev/tty.usbmodem1101 --fqbn arduino:avr:uno file.ino
```
The files need to include a file that has the same name as the root folder to be compiled correctly by the arduino-cli. For example, if the root folder is called `project_name`, then the file `project_name.ino` needs to be included in the root folder,

