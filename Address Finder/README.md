# Address Finder
Address finder is a Qt based application that allows users to enter a latitude and a longitude of a place
and retrieve its full address displaying it in the debug console.

The application makes use of the **Google's Geocoding API** therefore it needs an active interent connection to work.
The application grabs the user input and requests the data from Google using a **QNetworkRequest**.
Once the Google API Server receives our request it will process the information and return a result back to us.
The result is in **XML Format** because I specified the format in the initial request, otherwise the Google API Server
would have returned its data in JSON Format.

Once Google returns the results to the application the getAddressFinished() slot function will be called and the data will be
obtained by using **QNetworkReply**. At the end, the data is processed by **QXmlStreamReader** to grab the data the application needs
and display it in the console.


![Alt text](https://github.com/RosarioAleCali/QtExamples/blob/master/Address%20Finder/Screenshot.PNG  "Program Screenshoot")
