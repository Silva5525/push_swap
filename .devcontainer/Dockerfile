# # Start von einem Basis-Image, normalerweise wird Ubuntu verwendet
# FROM mcr.microsoft.com/vscode/devcontainers/base:ubuntu

# # Vermeide Dialoge mit apt-get
# ARG DEBIAN_FRONTEND=noninteractive

# # Installiere GLFW, OpenGL und notwendige Pakete
# RUN apt-get update \
#     && apt-get install -y --no-install-recommends \
#     libglfw3 \
#     libglfw3-dev \
#     libglu1-mesa-dev \
#     freeglut3-dev \
#     mesa-common-dev \
#     software-properties-common \
#     build-essential \
#     wget \
#     && apt-get clean -y && rm -rf /var/lib/apt/lists/*

# # Download und Installation der neuesten CMake-Version
# RUN wget -O cmake-install.sh https://github.com/Kitware/CMake/releases/download/v3.20.5/cmake-3.20.5-Linux-x86_64.sh \
#     && chmod +x cmake-install.sh \
#     && ./cmake-install.sh --skip-license --prefix=/usr/local \
#     && rm cmake-install.sh

# # Setze DEBIAN_FRONTEND zurück
# ARG DEBIAN_FRONTEND=
# Start von einem Basis-Image, normalerweise wird Ubuntu verwendet
# FROM mcr.microsoft.com/vscode/devcontainers/base:ubuntu

# # Vermeide Dialoge mit apt-get
# ARG DEBIAN_FRONTEND=noninteractive

# # Installiere GLFW, OpenGL und notwendige Pakete
# RUN apt-get update \
#     && apt-get install -y --no-install-recommends \
#     libglfw3 \
#     libglfw3-dev \
#     libglu1-mesa-dev \
#     freeglut3-dev \
#     mesa-common-dev \
#     software-properties-common \
#     build-essential \
#     wget \
#     && apt-get clean -y && rm -rf /var/lib/apt/lists/*

# # Download und Installation der neuesten CMake-Version
# RUN wget -O cmake-install.sh https://github.com/Kitware/CMake/releases/download/v3.20.5/cmake-3.20.5-Linux-x86_64.sh \
#     && chmod +x cmake-install.sh \
#     && ./cmake-install.sh --skip-license --prefix=/usr/local \
#     && rm cmake-install.sh

# # Setze DEBIAN_FRONTEND zurück
# ARG DEBIAN_FRONTEND=
ARG VARIANT=debian-11
FROM mcr.microsoft.com/vscode/devcontainers/base:0-${VARIANT}

# Installiere GLFW, OpenGL, pkg-config und notwendige Pakete
RUN apt-get update \
    && apt-get install -y --no-install-recommends \
    libglfw3 \
    libglfw3-dev \
    libglu1-mesa-dev \
    freeglut3-dev \
    mesa-common-dev \
    software-properties-common \
    build-essential \
    wget \
    valgrind \
    pkg-config \ # Hinzugefügt pkg-config zur Installation
    && apt-get clean -y && rm -rf /var/lib/apt/lists/*

# Download und Installation der neuesten CMake-Version
RUN wget -O cmake-install.sh https://github.com/Kitware/CMake/releases/download/v3.20.5/cmake-3.20.5-Linux-x86_64.sh \
    && chmod +x cmake-install.sh \
    && ./cmake-install.sh --skip-license --prefix=/usr/local \
    && rm cmake-install.sh

# Setze DEBIAN_FRONTEND zurück
ARG DEBIAN_FRONTEND=
