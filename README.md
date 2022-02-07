# GameBook

## Current State

✅ Finish <br />
🔜 Close to be finish <br />
🏗️ Work In Progress <br />
❗ Not Began <br />

✅ Load .toml file. <br />
✅ Print the title. <br />
✅ Print the text.  <br />
✅ User Inputs handler. <br />
✅ Buttons. <br />
✅ Buttons Actions. <br />
✅️ Buttons Conditions. <br />

## Compilation
You must install powershell,
with chocolatey and the pacakge llvm.

## IDE

### Sublime Text
Tabulation set as 4, with dark default theme.

# Page File
Text limited as 441 chars. Thta will not crash, but thats too many for the default console size.

# index.csv
Use to load the good page according to the index .
It's used to load a page without load every pages.
Be careful with this file, that can crash the game.

## Example
[info]

title = "the title"

text = " the text / question "


[buttons]

btn_test = ["text", "action", "cond"]


## Warning
The '$' specified a line jump,
Place an empty space at the first char and last.

## Actions && Conditions && TextPage
## Format
(action).(arg)
The ; make seperate the actions or conditions.
Each data must end by a ';'.

Take a look in the wiki for tha actions and conditions.

# Code Rules

Variables: snake_case
Structures && Enum: CamelCase
