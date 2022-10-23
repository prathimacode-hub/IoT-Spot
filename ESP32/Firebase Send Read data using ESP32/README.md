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