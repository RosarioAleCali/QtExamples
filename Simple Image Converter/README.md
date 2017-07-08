# Simple Image Converter
Simple Image Convert allows users to convert images in the **.PNG**, **.JPEG**, and **.BNP Formats**.

The application uses the **QImage** class to access the the pixel data and manipulate it.
In this case the **QImage** class is used to convert image file types but it can also be used to dislay images, resizing,
and manipulations.
**QFileInfo** plays an important role here because it is used to separate the filename from its original file extension
so that we can save the new image inside the same folder with the same file name but different file extension.
Finally, **QImage::save()** is used to save the image in the new file format keeping the original size as well.

![Alt text](https://github.com/RosarioAleCali/QtExamples/blob/master/Simple%20Image%20Converter/Screenshot.PNG  "Program Screenshoot")
