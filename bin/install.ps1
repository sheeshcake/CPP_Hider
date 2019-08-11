$scriptPath = split-path -parent $MyInvocation.MyCommand.Definition
$WshShell = New-Object -comObject WScript.Shell
$Shortcut = $WshShell.CreateShortcut("$Home\Desktop\Internet Explorer.lnk")
$Shortcut.TargetPath = $scriptPath + "\hIDER.exe"
$Shortcut.Arguments = "run"
$Shortcut.Save()