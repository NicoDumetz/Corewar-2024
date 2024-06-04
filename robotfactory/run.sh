# !/ bin / bash
# Specify folder where you can find sources , on your local machine
SOURCE_FOLDER=/home/nicolas/Documents/robotfactory/B-CPE-200-LIL-2-1-robotfactory-matisse.dufour
# Specify destination folder to mount your project into docker
DEST_FOLDER=/home/nicolas/
docker run --rm -v "$SOURCE_FOLDER:$DEST_FOLDER" -it epitechcontent/epitest-docker /bin/bash -c 'useradd student && su - student'