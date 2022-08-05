# 🎇Contributing Guidelines

This documentation contains a set of guidelines to help you during the contribution process. 

I'm happy to welcome all the contributions from anyone willing to add new scripts to this repository. Thank you for helping out and remember,
**no contribution is too small.**


## 💻Before Contributing

Welcome to [prathimacode-hub/IoT-Spot](https://github.com/prathimacode-hub/IoT-Spot/). Before sending your pull requests, make sure that you **read the whole
guidelines**. If you have any doubt about the contributing guide, please feel free to reach out.


## 🙌Contribution

Any contribution is accepted, from fixing grammatical mistakes to implementing complex scripts. Please read this section if you are contributing your work.


### 🔖Steps to Contribute

Following are the steps to guide you:

* Step 1: Fork the repo Go to your Git terminal and clone it on your machine.
* Step 2: Add an upstream link to the main branch in your cloned repo
    ```
    git remote add upstream https://github.com/prathimacode-hub/IoT-Spot.git
    ```
* Step 3: Keep your cloned repo up to date by pulling from upstream (this will also avoid any merge conflicts while committing new changes)
    ```
    git pull upstream main
    ```
* Step 4: Create your feature branch (This is a necessary step, so don't skip it)
    ```
    git checkout -b <feature-name>
    ```
* Step 5: Commit all the changes (Write commit message as "Small Message")
    ```
    git commit -m "Write a meaningful but small commit message"
    ```
* Step 6: Push the changes for review
    ```
    git push origin <branch-name>
    ```
* Step 7: Create a PR on Github. (Don't just hit the create a pull request button, you must write a PR message to clarify why and what are you contributing)


### 🔨Note:

> - Do not edit/delete someone else's script in this repository. You can only insert new files/folders into this repository.

  > - Give a meaningful name to whatever file or folder you are adding. (E.g., if you have written a script on LED Blinking, then 
  > led_blinking.c is one example of the valid name)


## 🔑Guidelines

1. Welcome to this repository, if you are here as an open-source program participant/contributor.
2. Participants/contributors have to **comment** on issues they would like to work on, and mentors or the PA will assign you.
3. Issues will be assigned on a **first-come, first-serve basis.**
4. Participants/contributors can also **open their issues** using [issue_template](https://github.com/prathimacode-hub/IoT-Spot/tree/main/.github/issue_template),
but it needs to be verified and labelled by a mentor or PA. Please discuss with the team once before opening your issues. We respect all your contributions, whether 
it is an Issue or a Pull Request.
6. When you raise an issue, make sure you get it assigned to you before you start working on that project.
7. Each participant/contributor will be **assigned 1 issue (max)** at a time to work.
8. Participants are expected to follow **project guidelines** and [**coding style**](https://pep8.org/"). **Structured code** is one of our top priorities.
9. Try to **explain your approach** to solve any issue in the comments. This will increase the chances of you being assigned.
10. Don't create issues that are **already listed**.
11. Please don't pick up an issue already assigned to someone else. Work on the issues after it gets **assigned to you**.
12. Make sure you **discuss issues** before working on the issue.
13. Pull requests will be merged after being **reviewed** by a mentor or PA.
14. It might take **a day or two** to review your pull request. Please have patience and be nice.
15. Always create a pull request from a **branch** other than `main`.
16. Participants/contributors have to complete issues before the decided Deadline. If you fail to make a PR within the deadline, then the issue will be assigned to 
another person in the queue.
17. While making PRs, don't forget to **add a description** of your work.
18. Include issue number (Fixes: issue number) in your commit message while creating a pull request.
19. Make sure your solution to any issue is better in terms of performance and other parameters in comparison to the previous work.
20. We all are here to learn. You are allowed to make mistakes. That's how you learn, right!.


### 🧲Pull Requests Review Criteria

1. Please fill the **[PR Template](https://github.com/prathimacode-hub/IoT-Spot/blob/main/.github/pullrequest_template.md)** properly while making a Pull Request.
2. You must add your script into the respective **folders**.
3. Your work must be original, written by you not copied from other resources.
4. You must comment on your code or script where necessary.
5. Follow the proper [style guides](https://google.github.io/styleguide/) for your work.
6. For any queries or discussions, please feel free to drop a message.


## 📍Other points to remember while submitting your work:

We want your work to be readable by others; therefore, we encourage you to note the following:

- If LED Blinking is submitted, for example, the Folder Name should be "LED Blinking" and the File Name as "led_blinking.c" and will be pushed into the appropriate repository.
- File extension for code should be `.py` or `.c` or `.cpp`. 
- Strictly use snake_case (underscore_separated) in your file_name, as it will be easy to parse in future using scripts.
- Please avoid creating new directories if at all possible. Try to fit your work into the existing directory structure you have created for your project. If you want to, please contact me before doing so.
- The [README.md](https://github.com/prathimacode-hub/IoT-Spot/blob/main/.github/readme_template.md) file should be concise and clear about what the script is about and what it does.
- It should be documented briefly enough to let readers understand. 
- If you have modified/added code work, make sure that code works before submitting.
- If you have modified/added documentation work, ensure your language is concise and contains no grammar errors.
- Follow the project structure mentioned in [README](https://github.com/prathimacode-hub/IoT-Spot/blob/main/README.md)
- Do not update the [README.md](https://github.com/prathimacode-hub/IoT-Spot/blob/main/README.md) and [Contributing_Guidelines.md](https://github.com/prathimacode-hub/IoT-Spot/blob/main/CONTRIBUTING.md).

## 📝 Project Structure for IoT based Issues

Your projects should contain this flow to maintain similarity across all other projects. Make sure to note these things, before you create a PR.

Create a folder of your project title. (Example: If you want to add a LED blinking using 8051, then the project should be placed under **8051 Scripts** with project title named as "LED Blinking" and file name as "led_blinking.c" if it's a C file)

The project repository you had created would have :

**file_name.py** or **file_name.c** or **file_name.cpp** - This file is the project you have worked upon.

**README.md** - This file is must be included to get a good understanding of the project (Elaborate briefly about how it works using [README](https://github.com/prathimacode-hub/IoT-Spot/blob/main/.github/readme_template.md) template). 

**requirements.txt** - In this file, you should add all the requirements you need to make your project work which also illustrates the list of all components used specifically

**Images** - This folder would have all images added, be it screenshots or step by step process images. Also, the inclusion of block diagrams and emulator circuit diagrams are a must to portray the project efficiently.

Since this repo is purely technical, make sure you include "Block Diagrams" and "Emulator Prototype Circuit Diagrams" in "Images" and direct them to the README.md file

**Related files** - The other additional and related files would be added up in the "Related" folder.


## 📝 Project Structure for All Kind of Issues and PR's


Your projects should contain this flow to maintain similarity across all other projects. Make sure to note these things, before you create a issue or PR.

Create an issue with your idea, approach, your expected outcome and why it's useful to be necessary to be included in this project. For PR, include issue number along with PR template, it's details and compiled output screenshot

All the web related changes should go into [IoT-Spot Website]()


## 📖Resources

1. Markdown: Markdown is a lightweight markup language like HTML, with plain text formatting syntax. 
  * [Markdown Cheat-Sheet](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)

2. Git: Git is a distributed version control system for tracking changes in source code during software development. It is designed for coordinating work among programmers, but it can be used to track changes in any set of files.
  * [Videos to get started](https://www.youtube.com/watch?v=xAAmje1H9YM&list=PLeo1K3hjS3usJuxZZUBdjAcilgfQHkRzW)
  * [Cheat Sheet](https://www.atlassian.com/git/tutorials/atlassian-git-cheatsheet)


## 🤔Need more help?

You can refer to the following articles on the basics of Git and Github and also contact me, in case you are stuck:
- [Forking a Repo](https://help.github.com/en/github/getting-started-with-github/fork-a-repo)
- [Cloning a Repo](https://help.github.com/en/desktop/contributing-to-projects/creating-an-issue-or-pull-request)
- [How to create a Pull Request](https://opensource.com/article/19/7/create-pull-request-github)
- [Getting started with Git and GitHub](https://towardsdatascience.com/getting-started-with-git-and-github-6fcd0f2d4ac6)
- [Learn GitHub from Scratch](https://lab.github.com/githubtraining/introduction-to-github)


## 😇Tip from me

It always takes time to understand and learn. So, do not worry at all. I know you can do this**!💪


🎉 🎊 😃 Happy Contributing 😃 🎊 🎉
