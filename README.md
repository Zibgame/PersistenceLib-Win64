# ♾️ PersistenceLib-Win64

A lightweight and modular C++ library for managing Windows persistence mechanisms through a clean and explicit API.

Designed for low-level developers, cybersecurity practitioners, and system programmers who need precise control over persistence techniques without unnecessary abstraction.

---

## ⚙️ Features

* 🧩 Modular architecture
* 🧠 Simple and explicit API
* 🔄 Install / Detect / Remove workflow
* 🪟 Windows Registry persistence (Run key)
* 🧬 WMI event-based persistence (Filter / Consumer / Binding)
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
    wmi/
        wmi_install.cpp
        wmi_detect.cpp
        wmi_remove.cpp
    utils/
        path.cpp
    examples/
        basic.cpp

build/
    libpersistence.a
    *.exe
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
    REGISTRY,
    WMI
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
    persist_install(WMI, path);

    if (persist_detect(REGISTRY))
        persist_remove(REGISTRY);

    if (persist_detect(WMI))
        persist_remove(WMI);

    return 0;
}
```

---

## 🪟 Registry Persistence

Uses the Windows Run key:

```
HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Run
```

* ⚡ No admin privileges required
* 🧾 Stores executable path
* 🔁 Executed at user logon

---

## 🧬 WMI Persistence

Implements event-based persistence using:

* `__EventFilter`
* `CommandLineEventConsumer`
* `__FilterToConsumerBinding`

Trigger example:

```
SELECT * FROM Win32_LogonSession
```

* 🧠 Event-driven execution
* 🕵️ More stealth than registry-based methods
* ⚠️ May require elevated privileges depending on environment

---

## 📌 Notes

* Always use absolute paths
* Ensure the binary exists at runtime
* WMI persistence may be restricted by system policies or security tools
* Designed for extensibility (startup folder, scheduled tasks, etc.)

---

## 🎯 Roadmap

* 📁 Startup folder persistence
* ⏱ Scheduled task persistence
* 🧬 Multi-method orchestration
* 🔒 Improved stealth execution (no PowerShell)

---

## ⚖️ Disclaimer

This project is intended for educational purposes, system programming practice, and security research.

---

## 👤 Author

Zibgame
