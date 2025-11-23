# SeeSeeStar

**Simple cross-platform (Android & Windows) application using C++ Qt and C# .NET MAUI**

---

## Project Purpose

This project is designed to explore and demonstrate **cross-platform application development** using a hybrid tech stack:

- **Backend:** C++ with Qt 6.10.1 (Community Edition)  
- **Frontend:** C# using .NET MAUI  

The application allows users to:

- Create nodes on a graph using **latitude and longitude values**  
- Link nodes together to form **edges**, creating a complete graph  
- Compute the **shortest traversal** between two nodes using the **A* algorithm**  
- **Save and load** graphs between sessions  

The purpose of this project is to study scalable cross-platform development and showcase practical skills in both C++ and C#.

---

## Features

- Add nodes with latitude/longitude  
- Connect nodes with edges to form a graph  
- Find shortest path using A* search  
- Save and load graphs  
- Cross-platform support for **Windows** and **Android**

---

## Dependencies

- **Qt 6.10.1 Community Edition**  
  [Download Qt OSS](https://www.qt.io/download-qt-installer-oss)  
- **.NET / MAUI** for frontend  

> Note: Qt libraries are dynamically linked to comply with LGPL.

---

## Building the Project

### Backend (Qt C++)

1. Install Qt 6.10.1 (Community Edition)  
2. Open the `backend` folder in **Qt Creator**  
3. Build the project (dynamic linking to Qt)  

### Frontend (C# MAUI)

1. Install .NET SDK and MAUI workload  
2. Open the `frontend` folder in **Visual Studio**  
3. Reference the built backend shared library (DLL)  
4. Build and run  

---

## License

- **Backend & frontend code:** MIT License  
- **Qt libraries:** LGPL (Community Edition)
