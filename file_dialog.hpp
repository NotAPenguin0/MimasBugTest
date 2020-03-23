#pragma once

#include <filesystem>
#include <vector>
#include <string>

namespace fs = std::filesystem;

struct FileType {
    const wchar_t* name;
    const wchar_t* filter;
};

class FileDialog {
public:
    enum Flags {
		PickFiles = 1,
		PickFolders = 2
    };

    bool show(Flags flags, fs::path dir, std::vector<FileType> filetypes = {});
    fs::path get_result() const;

private:
    fs::path result;
};
