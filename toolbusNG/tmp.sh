JAVA_HOME=/usr/lib/jvm/java-1.5.0-sun-1.5.0_06

CLASS_PATH=/home/paulk/.eclipse/toolbusNG:/home/paulk/software/source/aterm-java:/home/paulk/software/source/shared-objects/bin:/home/paulk/software/source/shared-objects/shared-objects-1.4.jar:/home/paulk/software/source/JJTraveler/bin:/home/paulk/software/source/JJTraveler/jars/junit.jar:/home/paulk/software/source/JJTraveler/jjtraveler-0.4.3.jar:/home/paulk/.eclipse/toolbusNG/junit.jar::/usr/lib/jvm/java-1.5.0-sun-1.5.0_03/lib/tools.jar:

LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/share/eclipse/plugins/com.appperfect.teststudio_6.5.0/lib:
export LD_LIBRARY_PATH

"$JAVA_HOME"/bin/java -verboseGC -Xms1000m -Xmx1000m -classpath "$CLASS_PATH" -Xoptimize toolbus.Main --output-dir /tmp
