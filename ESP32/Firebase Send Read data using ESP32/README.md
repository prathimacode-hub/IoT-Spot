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

## ESP32 Store Data to Firebase Database

![ESP32 Firebase store data realtime database project example](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/08/ESP32-Firebase-store-data-realtime-database.png?resize=750%2C297&quality=100&strip=all&ssl=1)

Copy the following code to your Arduino IDE. This sketch inserts an int and a float number into the database every 15 seconds. This is a simple example showing you how to connect the ESP32 to the database and store data.  

**Note:** We are using version 2.3.7 of the Firebase ESP Client library. If you have issues compiling your code with more recent versions of the library, downgrade to version 2.3.7.

```c


#include <Arduino.h>
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>

//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

// Insert your network credentials
#define WIFI_SSID "REPLACE_WITH_YOUR_SSID"
#define WIFI_PASSWORD "REPLACE_WITH_YOUR_PASSWORD"

// Insert Firebase project API Key
#define API_KEY "REPLACE_WITH_YOUR_FIREBASE_PROJECT_API_KEY"

// Insert RTDB URLefine the RTDB URL */
#define DATABASE_URL "REPLACE_WITH_YOUR_FIREBASE_DATABASE_URL" 

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
int count = 0;
bool signupOK = false;

void setup(){
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")){
    Serial.println("ok");
    signupOK = true;
  }
  else{
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h
  
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void loop(){
  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0)){
    sendDataPrevMillis = millis();
    // Write an Int number on the database path test/int
    if (Firebase.RTDB.setInt(&fbdo, "test/int", count)){
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
    count++;
    
    // Write an Float number on the database path test/float
    if (Firebase.RTDB.setFloat(&fbdo, "test/float", 0.01 + random(0,100))){
      Serial.println("PASSED");
      Serial.println("PATH: " + fbdo.dataPath());
      Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      Serial.println("REASON: " + fbdo.errorReason());
    }
  }
}

```


You need to insert your network credentials, URL database, and project API key for the project to work.

This sketch was based on the  [basic example](https://github.com/mobizt/Firebase-ESP-Client/blob/main/examples/RTDB/Basic/Basic.ino)  provided by the library. You can find more examples  [here](https://github.com/mobizt/Firebase-ESP-Client/tree/main/examples).

### How the Code Works

Continue reading to learn how the code works, or skip to the  [demonstration section](https://randomnerdtutorials.com/esp32-firebase-realtime-database/#demo-write).

First, include the required libraries. The  WiFi.h  library to connect the ESP32 to the internet (or the  ESP8266WiFi.h  in case of the ESP8266 board) and the  Firebase_ESP_Client.h  library to interface the boards with Firebase.

```c
#include <Arduino.h>
#if defined(ESP32)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>
```

You also need to include the following for the Firebase library to work.

```c
//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"
```

Include your network credentials in the following lines.

```c
#define WIFI_SSID "REPLACE_WITH_YOUR_SSID"
#define WIFI_PASSWORD "REPLACE_WITH_YOUR_PASSWORD"
```

Insert your firebase project API key—the one you’ve gotten in  [section 4.1](https://randomnerdtutorials.com/esp32-firebase-realtime-database/#project-api-key).

```c
#define API_KEY "REPLACE_WITH_YOUR_FIREBASE_PROJECT_API_KEY"
```

Insert your database URL—[see section 3.4](https://randomnerdtutorials.com/esp32-firebase-realtime-database/#database-url).

```c
#define DATABASE_URL "REPLACE_WITH_YOUR_FIREBASE_DATABASE_URL"
```

#### setup()

In the  setup(), connect your board to your network.

```c
Serial.begin(115200);
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("Connecting to Wi-Fi");
while (WiFi.status() != WL_CONNECTED){
  Serial.print(".");
  delay(300);
}
Serial.println();
Serial.print("Connected with IP: ");
Serial.println(WiFi.localIP());
Serial.println();
```

Assign the API key and the database URL to the Firebase configuration.

```c
/* Assign the api key (required) */
config.api_key = API_KEY;

/* Assign the RTDB URL (required) */
config.database_url = DATABASE_URL;
```

The following lines take care of the signup for an anonymous user. Notice that you use the  signUp()  method, and the last two arguments are empty (anonymous user).

```c
/* Sign up */
if (Firebase.signUp(&config, &auth, "", "")){
  Serial.println("ok");
  signupOK = true;
}
else{
  Serial.printf("%s\n", config.signer.signupError.message.c_str());
}
```

**Note:** in the anonymous user signup, every time the ESP connects, it creates a new anonymous user.

If the sign-in is successful, the  signupOK  variable changes to  true.

```c
signupOK = true;
```

The library provides examples for other authentication methods like signing in as a user with email and password, using the database legacy auth token, etc. You can check all the examples for  [other authentication methods here](https://github.com/mobizt/Firebase-ESP-Client/tree/main/examples/Authentications). If you end up using other authentication methods, don’t forget that you need to enable them on your firebase project (_Build_ >  _Authentication_ >  _Sign-in method_).

#### loop()

In the  loop(), we’ll send data to the database periodically (if the signup is successful and everything is set up).

```c
if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0)){
```

#### Send Data to the Database

As mentioned in the library documentation, to store data at a specific node in the Firebase RTDB (realtime database), use the following functions:  set,  setInt,  setFloat,  setDouble,  setString,  setJSON,  setArray,  setBlob, and  setFile.

These functions return a boolean value indicating the success of the operation, which will be  true  if all of the following conditions are met:

-   Server returns HTTP status code 200.
-   The data types matched between request and response.Only  setBlob  and  setFile  functions that make a silent request to Firebase server, thus no payload response returned.

In our example, we’ll send an integer number, so we need to use the  setInt()  function as follows:

```c
Firebase.RTDB.setInt(&fbdo, "test/int", count)
```

The second argument is the database node path, and the last argument is the value you want to pass to that database path—you can choose any other database path. In this case, we’re passing the value saved in the  count  variable.

Here’s the complete snippet that stores the value in the database and prints a success or failed message.

```c
if (Firebase.RTDB.setInt(&fbdo, "test/int", count)) {
  Serial.println("PASSED");
  Serial.println("PATH: " + fbdo.dataPath());
  Serial.println("TYPE: " + fbdo.dataType());
}
else {
  Serial.println("FAILED");
  Serial.println("REASON: " + fbdo.errorReason());
}
```

We proceed in a similar way to store a float value. We’re storing a random float value on the  test/float  path.

```c
// Write an Float number on the database path test/float
if (Firebase.RTDB.setFloat(&fbdo, "test/float", 0.01 + random(0, 100))) {
  Serial.println("PASSED");
  Serial.println("PATH: " + fbdo.dataPath());
  Serial.println("TYPE: " + fbdo.dataType());
}
else {
  Serial.println("FAILED");
  Serial.println("REASON: " + fbdo.errorReason());
}
```

### Demonstration

Upload the code to your ESP32 board. Don’t forget to insert your network credentials, database URL path, and the project API key.

After uploading the code, open the Serial Monitor at a baud rate of 115200 and press the ESP32 on-board reset button so it starts running the code.

If everything works as expected, the values should be stored in the database, and you should get success messages.

![ESP32 ESP8266 Store value firebase database Serial Monitor Success](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/08/ESP32-ESP8266-Store-value-to-firebase-database-Serial-Monitor-Success-1.png?resize=601%2C445&quality=100&strip=all&ssl=1)

Go to your project’s Firebase Realtime database, and you’ll see the values saved on the different node paths. Every 15 seconds, it saves a new value. The database blinks when new values are saved.

![ESP32 Store value firebase database Success](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/08/ESP32-store-value-to-firebase-database-success.png?resize=733%2C305&quality=100&strip=all&ssl=1)

Congratulations! You’ve successfully stored data in Firebase’s realtime database using the ESP32. In the next section, you’ll learn to read values from the different database’s node paths.

## ESP32 Read From Firebase Database

![ESP32 Firebase read data realtime database](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/08/ESP32-Firebase-read-data-realtime-database-04.png?resize=750%2C293&quality=100&strip=all&ssl=1)

In this section, you’ll learn how to read data from the database. We’ll read the data stored in the previous section. Remember that we saved an int value in the  test/int  path and a float value in the  test/float  path.

The following example reads the values stored in the database. Upload the following code to your board. You can use the same ESP32 board or another board to get the data posted by the previous ESP32.

**Note:** We are using version 2.3.7 of the Firebase ESP Client library. If you have issues compiling your code with more recent versions of the library, downgrade to version 2.3.7.

```c
#include <Arduino.h>
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>

//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

// Insert your network credentials
#define WIFI_SSID "REPLACE_WITH_YOUR_SSID"
#define WIFI_PASSWORD "REPLACE_WITH_YOUR_PASSWORD"

// Insert Firebase project API Key
#define API_KEY "REPLACE_WITH_YOUR_FIREBASE_PROJECT_API_KEY"

// Insert RTDB URLefine the RTDB URL */
#define DATABASE_URL "REPLACE_WITH_YOUR_FIREBASE_DATABASE_URL" 

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
int intValue;
float floatValue;
bool signupOK = false;

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")) {
    Serial.println("ok");
    signupOK = true;
  }
  else {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void loop() {
  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0)) {
    sendDataPrevMillis = millis();
    if (Firebase.RTDB.getInt(&fbdo, "/test/int")) {
      if (fbdo.dataType() == "int") {
        intValue = fbdo.intData();
        Serial.println(intValue);
      }
    }
    else {
      Serial.println(fbdo.errorReason());
    }
    
    if (Firebase.RTDB.getFloat(&fbdo, "/test/float")) {
      if (fbdo.dataType() == "float") {
        floatValue = fbdo.floatData();
        Serial.println(floatValue);
      }
    }
    else {
      Serial.println(fbdo.errorReason());
    }
  }
}

```

[View raw code](https://github.com/RuiSantosdotme/Firebase-ESP/raw/main/ESP-Firebase-Read-RTDB/ESP-Firebase-Read-RTDB.ino)

Don’t forget to insert your network credentials, database URL, and API key.

### How the Code Works

The code is very similar to the previous section’s example, but it reads data from the database. Let’s take a look at the relevant parts for this section.

Data at a specific node in Firebase RTDB can be read through the following functions:  get,  getInt,  getFloat,  getDouble,  getBool,  getString,  getJSON,  getArray,  getBlob,  getFile.

These functions return a boolean value indicating the success of the operation, which will be  true  if all of the following conditions were met:

-   Server returns HTTP status code 200
-   The data types matched between request and response.

The database data’s payload (response) can be read or access through the following Firebase Data object’s functions:  fbdo.intData,  fbdo.floatData,  fbdo.doubleData,  fbdo.boolData,  fbdo.stringData,  fbdo.jsonString,  fbdo.jsonObject,  fbdo.jsonObjectPtr,  fbdo.jsonArray,  fbdo.jsonArrayPtr,  fbdo.jsonData  (for keeping parse/get result), and  fbdo.blobData.

If you use a function that doesn’t match the returned data type in the database, it will return empty (string, object, or array).

The data type of the returning payload can be determined by fbdo.getDataType.

The following snippet shows how to get an integer value stored in the  test/int  node. First, we use the  getInt()  function; then, we check if the data type is an integer with  fbdo.dataType(), and finally, the  fdbo.intData()  gets the value stored in that node.

```c
if (Firebase.RTDB.getInt(&fbdo, "/test/int")) {
  if (fbdo.dataType() == "int") {
    intValue = fbdo.intData();
    Serial.println(intValue);
  }
}
else {
  Serial.println(fbdo.errorReason());
}
```

We use a similar snippet to get the float value.

```c
 if (Firebase.RTDB.getFloat(&fbdo, "/test/float")) {
  if (fbdo.dataType() == "float") {
    floatValue = fbdo.floatData();
    Serial.println(floatValue);
  }
}
else {
  Serial.println(fbdo.errorReason());
}
```

### Demonstration

Upload the code to your board. Then, open the Serial Monitor at a baud rate of 115200. After a few seconds, it will print the values saved on the database.

![ESP32 Store value firebase database Serial Monitor Success](https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2021/08/Get-values-from-Firebase-database-ESP32.png?resize=601%2C375&quality=100&strip=all&ssl=1)