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
❗ Installer <br />

## Compilation
You must install powershell,
with chocolatey and the pacakge llvm.

## Game Timeline

### Main Menu
The user can load a save, exit the game,
or start a new game,
and select the language.

#### Buttons
- Play
- Saves
- Exit

### Game
- Print achar file.
- Print page Information.
- Print player info.
- Print buttons.

### Final
- Print achar file.
- Ask to restart.

## IDE

### Sublime Text
Tabulation set as 4, with dark default theme.

## ACHAR
Contain the characters of the ascii art.

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

## List

### Action
- goto # Load another page
- none # No action
- cantdoc # Save than you saved the neightbor son
- cantoth # Give the food in the inventory
- cbmd # Crushed by a metal bar (<=5/6 == death)
- cggi # Captain give a good image of you +1 sociability
- cbr # Crashed by a rock (<5/6=death)

### Condition
- none # No Condition
- doc # Must be a doctor
- geo # Must be a geologist
- eng # Must be an enginer

# files.txt
List all files,
if one missing, it will be download from the cloud.
Link: REPLACE THIS BY THE LINK

# Code Rules

Variables: snake_case
Structures && Enum: CamelCase