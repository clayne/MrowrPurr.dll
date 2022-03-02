scriptName FileSystem hidden
{TODO documentation}

string[] function List(string path) global native
{TODO documentation}

bool function Exists(string path) global native

bool function IsFile(string path) global native

bool function IsDirectory(string path) global native









bool function Watch(string path, string callback, string filter = "") global native

bool function StopWatching(string path)

string function DataFolder() global native

string function SkyrimFolder() global native

string function SkyrimDocumentsFolder() global native

bool function IsAllowedPath(string path) global native

string[] function GetAllowedPaths() global native
