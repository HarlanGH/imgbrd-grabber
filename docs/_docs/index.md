---
title: 快速入门
permalink: /docs/
---


# 安装

## Windows

1. 下载最新版本 [here](https://github.com/Bionus/imgbrd-grabber/releases/latest)。
2. 根据说明安装程序。默认程序会安装到 "C:/Program Files/Grabber" (你的所有设置都会放在"%USERPROFILE%/AppData/Local/Bionus/Grabber")。
3. 如果在安装结束时没有选中“Start Grabber”，请转到安装文件夹，然后启动“Grabber.exe”(或者使用安装过程中在桌面上创建的快捷方式)。

## Arch Linux
For Arch Linux users, there are packages on the AUR
* [imgbrd-grabber-bin](https://aur.archlinux.org/packages/imgbrd-grabber-bin) which pulls the latest `tar.gz` release.
* [imgbrd-grabber-appimage](https://aur.archlinux.org/packages/imgbrd-grabber-appimage) which pulls the latest `appimage` release.
* [imgbrd-grabber](https://aur.archlinux.org/packages/imgbrd-grabber) which builds the package from source.

Install by issuing the command, substituting the package you want to install: `paru -Sy imgbrd-grabber-bin`

## Linux
Compile Grabber by following the instructions on the [Compilation]({{ site.baseurl }}{% link _docs/compilation.md %}#linux) page. Upon completion run `make install`.

### Linux Configuration
After installation you will need to copy the example configuration files from `$INSTALLATIONPREFIX/Grabber/example/` to your local Grabber directory, usually `~/.Grabber/`. Grabber will not run without these files.

# 使用

## 第一次使用

When you first start the program, you should be welcomed with this window:  
当你第一次启动该程序时，你将会看到这个界面：

![startup window](img/firstlaunch.png)

There are four fields to fill:  
这里有四个字段需要填写:

* Language: 界面语言
* Source: 下载来源
* Folder: 存储路径
* Filename: Grabber最强大的功能就是文件名格式化！查看细节 [Filename]({{ site.baseurl }}{% link _docs/filename.md %}) 。默认的 `%md5%.%ext%` 是个不错的选择。

*Note: if you have ignored the window that opened at first launch, you can set these settings in "Edit > Options".
Then, go the the "Save" part. Set the "Folder" and the "Filename" fields (it is in a subpart of the "Save" part, you may need to expand it).*

你现在应该可以看到类似下图的界面:

![startup window](img/start.png)

## 搜索

The upper part of the window is "divided" into two sections:

  * The search form: to make searches using tags. To insert a date, or access advanced features, you can click the "Plus" button. You can also browse other pages by changing the page value on the right.
  * Hidden form: you can show it by clicking the "+" button. Here, you have some fields to quickly change the settings (images per page and columns), the sources and "Post-filtering". Post-filtering allows you, for example, to bypass the two tags limitation of Danbooru by adding additional tags or metas (source, id, height, etc.) in this field. Note that none of these fields will be saved at exit, so if you want to definitely change the number of images per page or columns for example, you have should change them directly in the options.

After searching for something, you should see something as:

![search results](img/search.png)

## Downloading

### Batch downloads

To download a lot of pictures at the same time, first search for the tag you want to download (or no tag if that's what you want). You should arrive on the search page. From here, just click "Get this page" to download all the images on the page you are currently seeing (usually around 20 images), or "Get all" to download all the results of your search, including further pages (can go from 1 images to thousands).

Then, go to the "Downloads" tab to see a summary of what will be downloaded:

![downloads tab](img/downloadpage.png)

Once you are satisfied with your download list, click the "Download" button to start the download. The Batch Download window should appear:

![batch download window](img/batchdownload.png)

It lists all the images that will be or have already been downloaded. Now, you just have to wait. When all images are downloaded, the program wil show you a summary:

![download finished window](img/downloadfinished.png)

Success!

### Single images

To download single images, you have to "Ctrl + click" the images you want to download in the search window. They should then be marked in blue.

![single image selection](img/getselected.png)

One you have selected all the images you want to download, click the "Get selected" button. It will mark these images to be downloaded in the "Downloads" tab:

![single image downloads tab](img/downloadselected.png)

Once you are satisfied with your download list, click the "Download" button.

## Sources

### Basic usage

If you want to change the source of the pictures, just click the "Sources button" at the bottom of the window:

![sources window](img/sources.png)

Here, you just have to check the sources you want and then click "Ok".

### Multiple sources

If you select multiple sources, they will be put in one column by default. You can change this behavior by editing the "Columns" settings in the options.

Note that you can also merge all results to remove duplicates checking the "Merge results" option at the bottom of the window. It is useful if you browse from sites than mirror each others, while still having their own uploaders.

### Logging in

Some sources (for example Danbooru or Gelbooru) require to login to enable full API access. Even though it is usually not mandatory thanks to the regex fallback, it is usually strongly advised to do so.

To log into a source using an account, just enter your credentials in the "Credentials" tab of the Source Settings window:

![credentials form](img/sourcecredentials.png)

When you're done, you can click the "Test" button to check if your credentials are correct. Note that not all sources support login checking.

![credentials test success](img/sourcecredentialssuccess.png)

Success!
