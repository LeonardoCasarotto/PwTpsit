<h1>Research and File Reorganization Project</h1>


<h2>Introduction</h2>
<p>
Our project consists of creating a utility for file research and reorganization using concurrent programming. We have developed this solution using the <a href="https://qt.io">Qt framework</a>, which allowed us to provide a graphical user interface (GUI) for the <a href="https://isocpp.org">C++ language.</a></p>


<h2>Development Environment</h2>

<p>First of all, we worked on a UNIX-based operating system to be able to use the POSIX standards in our project.
  <br>In particular, the distribution we chose is <a href="https://endeavouros.com">EndeavourOs</a>, based on Arch Linux. To develop the software, we used the <a href="https://github.com/qt-creator/qt-creator">QtCreator</a> software. POSIX standard is required to use multithreading.</p>

<h2>Main Features</h2>

<p>The main functions of our project are:</p>

<ul>
   <li>Selection of the folder in which to perform the search and reorganization operations;</li>
   <li>Search for specific files or folders based on their names;</li>
   <li>Search for a word within all .txt files;</li>
   <li>Creation of ordered folders containing alphabetically sorted files;</li>
   <li>Creation of folders that group files of the same type;</li>
   <li>Creation of folders that divide files based on their size;</li>
   <li>Alphabetical sorting and renaming of files using a numeric code;</li>
   <li>Sorting by creation date, from least recent to most recent, using a numeric code;</li>
   <li>Creation of folders that divide files based on the owner.</li>
</ul>


<h2>Getting Started</h2>
<p>It is highly recommended to run the software on a Linux operating system. To run the software, you can directly download the executable file from the <a href="https://github.com/LeonardoCasarotto/PwTpsit/releases">release</a> section of this repository, or if you have Qt Creator on your computer, you can download the <a href="https://codeload.github.com/LeonardoCasarotto/PwTpsit/zip/refs/heads/main?token=AOV4HFHDZTCIN4KL5R24HDLEO6PHE">source code</a> to compile it.
  <br>
  From the terminal:
  
```console
  
$ git clone https://github.com/leonardocasarotto/PwTpsit.git
  
```
  
Please note that since this repository is currently private, you will need to log in with your GitHub username and a <a href="https://docs.github.com/en/authentication/keeping-your-account-and-data-secure/creating-a-personal-access-token">token</a> with access to the repository.</p>
  
<h2>Interface</h2>
<img src="./Dependencies/imgs/init.png?raw=true" float="left"><p float="right">When launched, the program displays a prompt asking the user to navigate to the initial folder from which to run the program. Of course, it will still be possible to change the folder afterwards.</p>
<img src="./Dependencies/imgs/fileViews.png?raw=true"<p>Once the folder is selected, a list of all the files and folders within it will appear, easily recognizable by their dedicated icon based on the file type. From the menu bar located at the top section of the screen, you can perform all the main functions of the program, including searching for further details in the software's <a href="https://github.com/LeonardoCasarotto/PwTpsit/wiki">Wiki.</a><br><b>Currently, the software and the wiki are only available in Italian language.</b></p>

<h2>Note:</h2>
<p>This project is a school assignment.</p>
<!--
<h2> Creators </h2>
![WhatsApp Image 2023-05-30 at 21 11 27](https://github.com/LeonardoCasarotto/PwTpsit/assets/98023003/8316e328-56bb-46ff-acc6-270a2a6878cc)
![WhatsApp Image 2023-05-30 at 21 10 55](https://github.com/LeonardoCasarotto/PwTpsit/assets/98023003/0716d7de-25ff-4c40-b788-f1394f885193)
![WhatsApp Image 2023-05-30 at 21 16 58](https://github.com/LeonardoCasarotto/PwTpsit/assets/98023003/82987956-535c-47c4-ae62-610fc94beb4e)
![WhatsApp Image 2023-05-30 at 21 13 24](https://github.com/LeonardoCasarotto/PwTpsit/assets/98023003/c23fc8c4-f6cb-4bbc-80f4-7101695e32d5) -->
