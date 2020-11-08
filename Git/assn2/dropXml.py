#!/usr/bin/env python3
#
# Description: Walks down a given directory, creating an xml file based off of a README in that directory
# Author: Nicholas Sica

import sys
import os

# Parses the readme and returns a dictionary for use in dirWalk
def parseREADME(currDir):
	readmeLoc = os.path.join(currDir, "README")
	readmeDict = {"index":[], "required":[]}
			
	if os.path.exists(readmeLoc):
		with open(readmeLoc, "r") as readme:
			for line in readme:
				lineList = line.split(":")
				readmeDict[lineList[0]] = lineList[1:len(lineList)] 
	return readmeDict

# Creates index.html using the dictionary that was passed in
def createIndex(currDir, readmeDict):
	with open(os.path.join(currDir,"dir.xml"), "w") as index:
		print("<?xml version=\"1.0\" encoding=\"ISO-8859-1\"?>", file=index)
		print("<direntry>", file=index)

		for key, items in readmeDict.items():
			print("	<%s>" % (key), file=index)
			for item in items:
				if item != "":
					if item[0] == "d":
						print("		<dir>%s</dir>" % (item[1:len(item)].strip()), file=index)
					elif item[0] == "f":
						if "Socket" in item or "socket" in item:
							print("		<sock>%s</sock>" % (item[1:len(item)].strip()), file=index)
						elif "Pipe" in item or "pipe" in item:
							print("		<fifo>%s</fifo>" % (item[1:len(item)].strip()), file=index)
						elif item != "fdir.xml":
							print("		<file>%s</file>" % (item[1:len(item)].strip()), file=index)

			print("	</%s>" % (key), file=index)
		print("</direntry>", file=index)

# Walks through the directories and sets the list up to be used in createIndex
def dirWalk(topDir):
	for root, dirs, files in os.walk(topDir):
		readmeDict = parseREADME(root)
		others = {"dirs": dirs, "files": files}
		for key, items in readmeDict.items():
			others["dirs"] = [dir for dir in others["dirs"] if dir not in items]
			others["files"] = [file for file in others["files"] if file not in items]
			items = ["d"+item if item in dirs else "f"+item for item in items]
			readmeDict[key] = items

		readmeDict["other"] = ["d"+dir for dir in others["dirs"]] + ["f"+file for file in others["files"]]
		print(readmeDict)
		createIndex(root, readmeDict)

# Checks for the amount of arguments and passes the correct directory to dirWalk
def main(args):
	if len(args) > 2:
		print("Too many arguments!")
	else:
		topDir = ""
		if len(args) == 1:
			topDir = os.getcwd()
		else:
			topDir = args[1]
			
		dirWalk(topDir)

if __name__ == "__main__":
	main(sys.argv)
