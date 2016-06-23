#!/bin/bash
java -cp .:bin:lib/exificient.jar:lib/xercesImpl.jar EXIficientDemo sample-data/notebook.xml sample-data/notebook.xsd
