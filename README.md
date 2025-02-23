# Shuck
Shuck is a lightweight command-line utility that provides various functionalities.<br>

## Basic Usage
All commands are prefixed with shuck when executed.

```bash
shuck <command> [arguments]
```

Available Commands
|Command|	Description|
|----|-------------|
|help|	Displays all available Shuck commands.|
|read| <filename>	Outputs the full content of a file with line numbers.|
|head|<filename>	Displays the first 10 lines of a file.|
|open|<file/url>	Opens a given file or URL.|
|ls	|Lists all folders and their contents using the tree /f command.
|search|<query>	Searches Google with the given query.|
|quit / exit	|Exits Shuck.|
|hyp	|Prompts user input for two sides of a right-angled triangle and calculates the hypotenuse, displaying a text-based triangle representation.|

## Examples
### Reading a file:
```bash
shuck read example.txt
```

### Viewing the first 10 lines of a file:
```bash
shuck head example.txt
```
### Opening a website or file:
```bash
shuck open https://example.com
```

### Listing files in the directory:
```bash
shuck ls
```

### Performing a Google search:
```bash
shuck search programming tutorials
```
### Calculating the hypotenuse of a right triangle:

```bash
shuck hyp
```
*(You will be prompted to enter two side lengths.)*
