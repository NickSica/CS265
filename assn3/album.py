#!/usr/bin/env python3

class Album:
    name = ""
    releaseDate = 0
    tracklist = []

    def __init__(self, name="", date=0, tracklist=[]):
        self.name = name
        self.date = date
        self.tracklist = tracklist

    def setName(self, name):
        self.name = name
    def getName(self):
        return self.name

    def setReleaseDate(self, date):
        self.date = date
    def getReleaseDate(self):
        return self.date
    
    def addSong(self, song):
        tracklist.append(song)
    def getTracklist(self):
        return self.tracklist
