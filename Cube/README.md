# Cube
Cube is a simple progam that showcases the use of **OpenGL** inside of **Qt**.</br>
The program renders a **3D Cube** rotating on it self which can be moved around the screen using the A, W, S, D Keys on your Keyboard.</br>
**3D Rendering** is made possible by enabling the **GL_DEPTH_TEST** and clearing the **GL_DEPTH_BUFFER_BIT** (Very important to render the next image correctly).</br>
**gluPerspective()** is used to set up a perspective projection matrix so that the graphics seem to have depth and distance.</br>
The rotation happens thanks to the use of **glRotatef()** and the Cube is positioned by using **glTranslatef()**.</br>
**Texturing** and **Lightning** are also applied to th Cube to give it a more realistic look.
It is very important to call **update()** manually because otherwise the cube will not be animated.</br>

![Alt text](https://github.com/RosarioAleCali/QtExamples/blob/master/Cube/Screenshot_1.PNG  "Program Screenshoot")
![Alt text](https://github.com/RosarioAleCali/QtExamples/blob/master/Cube/Screenshot_2.PNG  "Program Screenshoot")
![Alt text](https://github.com/RosarioAleCali/QtExamples/blob/master/Cube/Screenshot_3.PNG  "Program Screenshoot")
