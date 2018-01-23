#!/user/bin/python

import sys
import datetime

dt = datetime.datetime.now()
dtstr = dt.strftime("%Y-%m-%d %H:%M:%S")


filename = sys.argv[1]
authorName = "Guangzhuan Mo"
studentID = "5920187"
programNum = sys.argv[2]
title = sys.argv[3]
openComment =	"/* ===========================================================\n" 
documentTemplate ="""|
|  
| 	 date: {5}
| Source code: {0} 
|      Author: {1}
| Student ID : {4}
| Assignment : Program#  {2}  {3} 
|      Course: COP 4338 (Advanced Programming) 
|    Section : U01 
|  Instructor: William Feild 
|    Due Date: 
|    
|      I hereby certify that this collcetive work is my own 
|      and none of it is the work of any other person or entiry. 
|      _________________________________________[{1}]
|
|    Language: C
| Compile/Run:
|	gcc {0} -o filename
|
| +---------------------------------------------------------------
|
| Description:
|
| 	Input:
|
|      Output:
|
|     Process:
|	the program's steps are as follows:
|
| Required Features Not Included: 
|	All required features are included.
|
| Known Bugs:
| 	None;
|	the program operates correctly
|
""".format(filename, authorName, programNum, title, studentID, dtstr) 
closeComment =	" * ===========================================================*/\n"

file = open(filename, "w")
file.write(openComment)
file.write(documentTemplate)
file.write(closeComment)
