# SETTINGS
$extension = "exe"

# SCRIPT
Write-Host "START"
$files = New-Object -TypeName 'System.Collections.ArrayList';

foreach($line in Get-Content ..\code\list.txt) {
    if($line -match $regex){
        $file_o = "";

        foreach($i in $line) {
           if ($i -match '#') {
                for($k = 0; $k -match $i; $i++) {
                    $file_o + $i;
                }
           } else {
                $file_o = $line;
           }
        }

        if ($file_o -ne "") {
            $files.add($file_o.trim());
        }
    }
}

clang -g $files -Wall -std=c17 -o ("../build/GameBook."+$extension) # CLANG Compilation Command

Add-Type -AssemblyName PresentationCore,PresentationFramework
$Result = [System.Windows.MessageBox]::Show("Start the Game ?","Game Builder",4,64)

if($result -eq "YES")
{
    Set-Location ../build
    Start-Process ("GameBook."+$extension)
    Set-Location ../cmp/
}

Write-Host "END";
