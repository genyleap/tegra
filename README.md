# Tegra System

![tegra-git-header-01](https://user-images.githubusercontent.com/4066299/186493497-248baa36-e488-4573-b373-c4f8b3da5979.svg)

[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)

Welcome to the Tegra development repository!
Tegra is an open source super-high end performance, user-friendly, multi-lingual and multi-purpose modern system based on **C++20** which enables you to build websites and powerful online applications.

[![GitHub issues](https://img.shields.io/github/issues/genyleap/tegra)](https://github.com/genyleap/tegra/issues)
[![GitHub forks](https://img.shields.io/github/forks/genyleap/tegra)](https://github.com/genyleap/tegra/network)
[![GitHub stars](https://img.shields.io/github/stars/genyleap/tegra)](https://github.com/genyleap/tegra/stargazers)
[![GitHub license](https://img.shields.io/github/license/genyleap/tegra)](https://github.com/genyleap/tegra/blob/main/LICENSE)
![Language iso: C++](https://img.shields.io/badge/C%2B%2B-20-blue)
![Platforms](https://img.shields.io/badge/Platform%20Support-macOS%2C%20Linux%2C%20Windows-lightgrey)
![Status](https://img.shields.io/badge/Status-Under%20Development-red)

***WARNING:*** Tegra's code is not ready for final use at the moment, but you can see development stages in dev repository.

***WARNING:*** Errors may occur frequently during the build process.

## Technical Features
- Written by C++
- Cross-Platform base structure
- Super-High end performance
- Efficient use of resources
- Compiled generation of web pages
- Smart page optimization
- Smart api generator for external purposes
- Integrated core structure for desktop, mobile, IoT and wasm technology.

## Basic Default Applications
- Core Service
- CMS
- Blogger
- Gallery
- Commerce
- Web Service
- Web Master

## Basic Features
- Multi-Language support
- Multi-Purpose
- SEO Optimizer & Manager
- File Manager
- Error Page Manager
- Website Navigation
- Static Pages
- Content Categories
- Social Network Manager
- User Account
- User Group
- User Rating
- User Comments
- User Sharing Tool
- Content Editor Quill, CKEditor and TinyMCE
- Content Tagging
- Content Blocks or Widgets
- Extensions, Modules or Plugins
- Themes and Layouts
- Upload and Download manager
- Input formats like Markdown, HTML etc
- Developer Mode
- Bootstrap 5.x based template support
- Resize images on fly with caching

## Future features
_Features that will be added in the future_
- Web3 & Decentralized  Support
- Cloud Storage on AWS & Google
- Bitcoin & Ethereum blockchain network integration.
- IPFS/Filebase System support for decentralized storage
- Digital currency payment gateway for BTC, ETH & USDT

## Default Modules
- [ ] Index
- [ ] Error Page
- [ ] Menu 
- [ ] Langing Page
- [ ] Static Page
- [ ] News
- [ ] Blog/Articles
- [ ] Send Feed Back
- [ ] Conversation
- [ ] Ticket
- [ ] Commerce
- [ ] Clubs
- [ ] Forums

## Default Features
- [ ] Template Editor
- [ ] SEO Manager
- [ ] Site Map Generator
- [ ] Resource Manager
- [ ] Google Webmaster Tool
- [ ] Google Analytics Tool
- [ ] Social Media
- [ ] Task System


## Platforms version:
- [x] Web
- [ ] Desktop
- [ ] Mobile

## Requirements
- C++20 or above (2a recommended).
- Drogon Webserver 1.7.5 or above.
- OpenSSL 3.x
- MySQL(MariaDB) or PostgreSQL
- Redis

## Building

- You need CMake tool for building source code
- CMake 3.18 or higher is required.

- The first step is to build the core system.
- After step one, build the modules and plugins.
- Finally, build the Tegra application.

```
cd tegra/build
cmake -DPLATFORM_OS="your_os" -DUSE_NONE_STL_JSON=true -DUSE_FMT=true ..
make

cd tegra/source/modules/xxx
cmake -DPLATFORM_OS="your_os" -DUSE_NONE_STL_JSON=true -DUSE_FMT=true ..
make

cd tegra/source/plugins/xxx
cmake -DPLATFORM_OS="your_os" -DUSE_NONE_STL_JSON=true -DUSE_FMT=true ..
make

cd tegra/application
cmake -DPLATFORM_OS="your_os" -DUSE_NONE_STL_JSON=true -DUSE_FMT=true ..
make

./Tegra

```

## TOOD
- Bug fixing.
- Add new exception handler.
- Add new features.
- Support new libraries.
- Tell me your opinion about which other items should be added.

## Contribution
- Bug fixes, docs, and enhancements welcome! Please let me know kambiz.ceo@gmail.com
