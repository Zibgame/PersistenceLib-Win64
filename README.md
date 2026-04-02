# 🔐 PersistenceLib-Win64

A lightweight C++ library for managing Windows persistence mechanisms with a clean, modular API.

Designed for low-level developers, cybersecurity enthusiasts, and system programmers who want precise control over persistence techniques without unnecessary abstraction.

---

## ⚙️ Features

* 🧩 Modular architecture
* 🧠 Simple and explicit API
* 🔄 Install / Detect / Remove workflow
* 🪟 Windows Registry persistence (Run key)
* 📦 Static library (.a) ready for integration

---

## 🧱 Project Structure

```
include/
    persistence.hpp

src/
    core/
        persistence.cpp
    registry/
        registry_install.cpp
        registry_detect.cpp
        registry_remove.cpp
    utils/
        path.cpp
    examples/
        basic.cpp

build/
    libpersistence.a
    basic.exe
```

---

## 🚀 Build

Using MinGW:

```
mingw32-make
```

Clean rebuild:

```
mingw32-make re
```

---

## 🔗 Linking the Library

### Compile your program with:

```
g++ main.cpp -Iinclude -Lbuild -lpersistence -o app.exe
```

### Explanation

* `-Iinclude` → include headers
* `-Lbuild` → locate the static library
* `-lpersistence` → link against libpersistence.a

---

## 🧠 API Overview

### Enum

```
enum PersistType
{
    REGISTRY
};
```

---

### Install Persistence

```
bool persist_install(PersistType type, const std::string& path);
```

➡️ Registers the given executable for persistence.

* `type` → persistence method
* `path` → absolute path to the executable

---

### Detect Persistence

```
bool persist_detect(PersistType type);
```

➡️ Checks if persistence is currently active.

Returns:

* `true` → active
* `false` → not present

---

### Remove Persistence

```
bool persist_remove(PersistType type);
```

➡️ Removes previously installed persistence.

---

## 🧪 Example Usage

```
#include "persistence.hpp"

int main()
{
    std::string path = get_self_path();

    persist_install(REGISTRY, path);

    if (persist_detect(REGISTRY))
    {
        persist_remove(REGISTRY);
    }

    return 0;
}
```

---

## 🪟 Registry Method Details

This module leverages the Windows Run key:

```
HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run
```

* ⚡ No admin privileges required
* 🧾 Stores executable path as a string value
* 🔁 Executed automatically at user logon

---

## 📌 Notes

* Always use absolute paths
* Ensure the binary exists at runtime
* Designed for extensibility (startup folder, scheduled tasks, etc.)

---

## 🎯 Roadmap

* 📁 Startup folder persistence
* ⏱ Scheduled task integration
* 🧬 Multi-method persistence orchestration

---

## ⚖️ Disclaimer

This project is intended for educational purposes, system programming practice, and security research.

---

## 👤 Author

Zibgame
