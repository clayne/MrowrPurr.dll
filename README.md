# Papyrus `FileSystem`

> SKSE plugin providing a variety of useful Papyrus functions  
> for interacting with the file system.

### Functions

```psc
; string Skyrim()
; string Data()
; string MyDocuments()
; string DocumentsGameDirectory()

bool Exists(string path)

string[] List(string path = ", filter = "", pattern = "", extension = "", recursive = false, files = true, folders = true)

bool IsDirectory(string path)
bool MakeDirectory(string path, recursive = true)
bool RemoveDirectory(string path, recursive = false)
bool CopyDirectory(string fromPath, string toPath, recursive = false)
bool MoveDirectory(string fromPath, string toPath, recursive = false)

bool IsFile(string path)
bool WriteToFile(string path, string text, append = false)
string ReadFromFile(string path)
bool CopyFile(string fromPath, string toPath)
bool MoveFile(string fromPath, string toPath)

Modified time
Size

Watch
```
