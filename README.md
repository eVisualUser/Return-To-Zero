# Return To Zero
You can download the full game, in the [releases](https://github.com/eVisualUser/Return-To-Zero/releases).

## Compilation Dependencies
You must install [owershell](https://docs.microsoft.com/fr-fr/powershell/scripting/install/installing-powershell?view=powershell-7.2),
with [chocolatey](https://community.chocolatey.org/) and the pacakge [llvm](https://community.chocolatey.org/packages/llvm).

# Page File
Text limited as 441 chars. Thta will not crash, but thats too many for the default console size.

# index.csv
Use to load the good page according to the index .
It's used to load a page without load every pages.
Be careful with this file, that can crash the game.

## Example
```
[info]

title = "the title"

text = " the text / question "


[buttons]

btn_test = ["text", "action;", "cond;"]
```
The '$' is used for go to the next line. 

## Actions && Conditions && TextPage
## Format
(action).(arg)
The ; make seperate the actions or conditions.
Each data must end by a ';'.

Take a look in the wiki for the actions and conditions.
