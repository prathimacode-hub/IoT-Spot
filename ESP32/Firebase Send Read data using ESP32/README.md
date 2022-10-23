# ESP32: Getting Started with Firebase (Realtime Database)

This guide will get you started quickly with Firebase using the ESP32 board. Firebase is Google’s mobile application development platform that includes many services to manage data from IOS, Android, or web applications. You’ll create a Firebase project with a realtime database (RTDB), and you’ll learn how to store and read values from the database with your ESP32.

![Getting Started with ESP32 with Firebase: Realtime Database Arduino IDE](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/08/ESP32-Getting-Started-Firebase.jpg?resize=828%2C466&quality=100&strip=all&ssl=1)



## What is Firebase?

![Firebase logo Realtime Database](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/08/Firebase-logo.png?resize=750%2C211&quality=100&strip=all&ssl=1)

Firebase is Google’s mobile application development platform that helps you build, improve, and grow your app. It has many services used to manage data from any android, IOS, or web application.

The following paragraph clearly explains the advantages of using Firebase:

“_Firebase is a toolset to “build, improve, and grow your app”, and the tools it gives you cover a large portion of the services that developers would normally have to build themselves_  _but don’t really want to build because they’d rather be focusing on the app experience itself. This includes things like analytics, authentication, databases, configuration, file storage, push messaging, and the list goes on_. The services are hosted in the cloud _and scale with little to no effort on the part of the developer_.”

This paragraph was taken from  [this article](https://medium.com/firebase-developers/what-is-firebase-the-complete-story-abridged-bcc730c5f2c0), and we recommend that you read that article if you want to understand better what firebase is and what it allows you to do.

You can use the ESP32 to connect and interact with your Firebase project, and you can create applications to control the ESP32 via Firebase from anywhere in the world.

In this tutorial, we’ll create a Firebase project with a realtime database, and we’ll use the ESP32 to store and read data from the database. The ESP32 can interact with the database from anywhere in the world as long as it is connected to the internet.

This means that you can have two ESP32 boards in different networks, with one board storing data and the other board reading the most recent data, for example.

![ESP32 Firebase Project Introduction realtime database](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/08/Firebase-ESP32-Project-Intro.png?resize=750%2C227&quality=100&strip=all&ssl=1)

In a later tutorial, we’ll create a web app using Firebase that will control the ESP32 to display sensor readings or control outputs from anywhere in the world.

![Firebase ESP32 Project Web App Project Example](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/08/Firebase-ESP32-Project-Web-App-Project-Example.png?resize=750%2C325&quality=100&strip=all&ssl=1)

## Project Overview

In this tutorial, you’ll learn how to create a Firebase project with a realtime database and store and read data from the database using the ESP32.

To follow this project, first, you need to set up a Firebase project and create a realtime database for that project. Then, you’ll program the ESP32 to store and read data from the database. This tutorial is divided into three sections.

1.  Create a Firebase Project
2.  ESP32: Store data to the Firebase Realtime Database
3.  ESP32: Read data from the Firebase Realtime Database

Let’s get started!

## Set Up a Firebase Account and Create a New Project

### 1.Create a New Project

Follow the next instructions to create a new project on Firebase.

1.  Go to  [Firebase](https://firebase.google.com/) and sign in using a Google Account.
2.  Click  _Get Started_, and then  _Add project_  to create a new project.
3.  Give a name to your project, for example:  _ESP32 Firebase Demo_.  
    ![Set Up Firebase Project for ESP32 and ESP8266 Step 1](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/08/1-Set-Up-Firebase-Project-ESP32-ESP8266.png?resize=680%2C550&quality=100&strip=all&ssl=1)
4.  Disable the option  _Enable Google Analytics_  for this project as it is not needed and click  _Create project_.  
    ![Set Up Firebase Project for ESP32 and ESP8266 Step 2](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/08/2-Set-Up-Firebase-Project-ESP32-ESP8266.png?resize=750%2C691&quality=100&strip=all&ssl=1)
5.  It will take a few seconds setting up your project. Then, click  _Continue_ when it’s ready.  
    ![Set Up Firebase Project for ESP32 and ESP8266 Step 3](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/08/3-Set-Up-Firebase-Project-ESP32-ESP8266.png?resize=750%2C391&quality=100&strip=all&ssl=1)  
    
6.  You’ll be redirected to your Project console page.  
    ![Set Up Firebase Project for ESP32 and ESP8266 Step 4](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/08/4-Set-Up-Firebase-Project-ESP32-ESP8266.png?resize=750%2C402&quality=100&strip=all&ssl=1)

### 2. Set Authentication Methods

You need to set authentication methods for your app.

“Most apps need to know the identity of a user. In other words, it takes care of logging in and identify the users (in this case, the ESP32). Knowing a user’s identity allows an app to securely save user data in the cloud and provide the same personalized experience across all of the user’s devices.” To learn more about the authentication methods, you can  [read the documentation](https://firebase.google.com/docs/auth).

1.  On the left sidebar, click on  _Authentication_ and then on  _Get started_.  
    ![Set Up Firebase Project for ESP32 and ESP8266 Authentication Methods](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/08/5-Set-Up-Firebase-Project-ESP32-ESP8266.png?resize=750%2C481&quality=100&strip=all&ssl=1)
2.  There are several authentication methods like email and password, Google Account, Facebook account, and others.![Set Up Firebase Project for ESP32 and ESP8266 Authentication Methods List](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/08/6-Set-Up-Firebase-Project-ESP32-ESP8266.png?resize=750%2C827&quality=100&strip=all&ssl=1)
3.  For testing purposes, we can select the  _Anonymous_ user (require authentication without requiring users to sign in first by creating temporary anonymous accounts). Enable that option and click  _Save_.![Set Up Firebase Project for ESP32 and ESP8266 Authentication Methods Anonymous User](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/08/7-Set-Up-Firebase-Project-ESP32-ESP8266.png?resize=828%2C315&quality=100&strip=all&ssl=1)

### 3. Creating a Realtime Database

The next step is creating a Realtime Database for your project. Follow the next steps to create the database.

1.  On the left sidebar click on  _Realtime Database_  and then, click on  _Create Database_.  
    ![Set up realtime database firebase ESP32 ESP8266 Step1](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/08/1-Set-Up-Firebase-database-ESP32-ESP8266.png?resize=750%2C573&quality=100&strip=all&ssl=1)
2.  Select your database location. It should be the closest to your location.  
    ![Set up realtime database firebase ESP32 ESP8266 Select Location](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/08/2-Set-Up-Firebase-database-ESP32-ESP8266.png?resize=750%2C372&quality=100&strip=all&ssl=1)
3.  Set up security rules for your database. For testing purposes, select  _Start in test mode_. In later tutorials you’ll learn how to secure your database using database rules.  
    ![Set up realtime database firebase ESP32 ESP8266 Set Security Rules](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/08/3-Set-Up-Firebase-database-ESP32-ESP8266.png?resize=776%2C478&quality=100&strip=all&ssl=1)
4.  Your database is now created. You need to copy and save the database URL—highlighted in the following image—because you’ll need it later in your ESP32 code.  
    ![Set up realtime database firebase ESP32 ESP8266 Database Created](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/08/4-Set-Up-Firebase-database-ESP32-ESP8266.png?resize=750%2C372&quality=100&strip=all&ssl=1)

The Realtime Database is all set. Now, you also need to get your project API key.

### 4. Get Project API Key

1.  To get your project’s API key, on the left sidebar click on  _Project Settings_.  
    ![Get Firebase Project API Key](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/08/1-Get-Firebase-Project-API-Key.png?resize=750%2C192&quality=100&strip=all&ssl=1)
2.  Copy the API Key to a safe place because you’ll need it later.  
    ![Firebase Project API key](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/08/2-Get-Firebase-Project-API-Key.png?resize=792%2C457&quality=100&strip=all&ssl=1)

Now, you have everything ready to interface the ESP32 with the database.

----------

## Program the ESP32 to Interface with Firebase

Now that the Firebase Realtime Database is created, you’ll learn how to interface the ESP32 with the database.

To program the ESP32, you can use  [Arduino IDE](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/),  [VS Code with the PlatformIO extension](https://randomnerdtutorials.com/vs-code-platformio-ide-esp32-esp8266-arduino/), or other suitable software.

**Note:** for firebase projects, we recommend using VS Code with the PlatformIO extension because if you want to develop a web application to make the bridge between the ESP32 and Firebase, VS Code provides all the tools to do that. However, we won’t build the web application in this tutorial, so you can use Arduino IDE.

### Install the Firebase-ESP-Client Library

There is a library with lots of examples to use Firebase with the ESP32: the  [Firebase-ESP-Client library](https://github.com/mobizt/Firebase-ESP-Client). This library is compatible with both the ESP32 and ESP8266 boards.

In this tutorial, we’ll look at simple examples to store and read data from the database. The library provides many other examples that you can check  [here](https://github.com/mobizt/Firebase-ESP-Client/tree/main/examples). It also provides detailed documentation explaining how to use the library.

#### Installation – VS Code + PlatformIO

If you’re using VS Code with the PlatformIO extension, click on the  **PIO Home**  icon and then select the  **Libraries tab**. Search for “**Firebase ESP Client**“. Select the  **Firebase Arduino Client Library for ESP8266 and ESP32**.

[![Install Firebase ESP Client Library VS Code](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/09/Install-Firebase-Library-VS-Code-1.png?resize=828%2C745&quality=100&strip=all&ssl=1)](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/09/Install-Firebase-Library-VS-Code-1.png?quality=100&strip=all&ssl=1)

Then, click  **Add to Project**  and select the project you’re working on.

[![Add Firebase ESP Client Library to Project VS Code](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/09/Install-Firebase-Library-VS-Code-2.png?resize=828%2C411&quality=100&strip=all&ssl=1)](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/09/Install-Firebase-Library-VS-Code-2.png?quality=100&strip=all&ssl=1)

Also, change the monitor speed to 115200 by adding the following line to the  platformio.ini  file of your project:

```c
monitor_speed = 115200
```

#### Installation – Arduino IDE

If you’re using Arduino IDE, follow the next steps to install the library.

1.  Go to  **Sketch** >  **Include Library**  >  **Manage Libraries**
2.  Search for  _Firebase ESP Client_  and install the  _Firebase Arduino Client Library for ESP8266 and ESP32_  by Mobitz.

**Note:** We are using version 2.3.7. If you have issues compiling your code with more recent versions of the library, downgrade to version 2.3.7.

![Install Firebase Arduino Client Library for ESP8266 and ESP32 by Mobitz](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/09/Install-Firebase-ESP-Client-Library-Arduino-IDE-f.png?resize=786%2C443&quality=100&strip=all&ssl=1)

Now, you’re all set to start programming the ESP32 board to interact with the database.

----------