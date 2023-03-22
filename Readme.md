<p align="center">
    <img src="https://cdn2.iconfinder.com/data/icons/strongicon-vol-24-free/24/filetype-16-512.png" width=138/>
</p>

<h1 align="center">cppplate</h1>

<div align="center">
    <a href="https://hub.docker.com/r/user/app" target="_blank">
    <img src="https://img.shields.io/docker/v/user/app"></a>
    <a href="https://github.com/user/app" target="_blank">
    <img alt="GitHub Repo stars" src="https://img.shields.io/github/stars/user/app?style=social">
</div>

> A modern C++2x project template, using [xmake](https://xmake.io/#/),
> [Github Actions](https://github.com/features/actions) and
> [Docker](https://www.docker.com/).


<!-- TOC start -->
- [Tools](#tools)
  * [Xmake](#xmake)
    + [Installing deps](#installing-deps)
    + [Building](#building)
    + [Running](#running)
    + [Installing](#installing)
    + [Project structure and configuration](#project-structure-and-configuration)
  * [Docker](#docker)
  * [Doxygen](#doxygen)
  * [Github Actions](#github-actions)
<!-- TOC end -->

<!-- TOC --><a name="tools"></a>
## Tools

<!-- TOC --><a name="xmake"></a>
### Xmake

[xmake](https://xmake.io/#/) is a fully-fledged and modern C++ package manager +
build system + project generator. For installation and usage refer to its docs.

<!-- TOC --><a name="installing-deps"></a>
#### Installing deps

```bash
xrepo install <PKG>
```

<!-- TOC --><a name="building"></a>
#### Building

```bash
xmake build <TARGET>
```

<!-- TOC --><a name="running"></a>
#### Running

```bash
xmake run <TARGET>
```

<!-- TOC --><a name="installing"></a>
#### Installing

```bash
xmake install
```

<!-- TOC --><a name="project-structure-and-configuration"></a>
#### Project structure and configuration

All the project configuration is done in the file `./xmake.lua`(refer to xmake
docs). The basic struture is as follows:

- A provider shared library that abstracts all the domain logic (classes,
  functions, ...). (**lib.a**)
- Any number of consumers targets that should use the provider library (e.g.
  **app**).
- A unit test target.
- A benchmark target.

<!-- TOC --><a name="docker"></a>
### Docker

The project use the [cppdev](https://github.com/Tomcat-42/cppdev) environment
for building.

The scripts `./scripts/build`, `./scripts/test` and `./scripts/publish` are
usefull for building the project inside a Docker container. Refer to the
`./Dockerfile` for configuration, multi-stage build and other tweaks.

<!-- TOC --><a name="doxygen"></a>
### Doxygen

This project uses the [Doxygen](https://www.doxygen.nl/) doc generation. Refer
the `./Doxyfile` for configuration. You can run `doxygen` for generating the
docs.

<!-- TOC --><a name="github-actions"></a>
### Github Actions

For a CI/CD pipeline, the [Github Actions](https://github.com/features/actions)
tool is used. The default configuration is located in
`./.github/workflows/cicd.yml`, and describes a simple **cascading** pipeline:

- The project is built in a container.
- The targets are copied to the host.
- Unit tests are executed.
- A docker image is published
- A github release is published.
