JAVA_HOME=/usr/lib/jvm/java-1.5.0-sun-1.5.0_10

CLASS_PATH=/home/paulk/.eclipse/toolbusNG:/home/paulk/software/installed2/aterm-java/share/aterm-java.jar:/home/paulk/software/installed2/shared-objects/share/shared-objects.jar:/home/paulk/software/installed2/JJTraveler/share/jjtraveler.jar:/usr/lib/jvm/java-1.5.0-sun-1.5.0_10/lib/tools.jar:

LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/share/eclipse/plugins/com.appperfect.teststudio_6.5.0/lib:
export LD_LIBRARY_PATH

MODULENAME=/home/paulk/research/relation-calculus/spec/RscriptCalculator

"$JAVA_HOME"/bin/java -server -classpath "$CLASS_PATH" toolbus.Main --output-dir /tmp -DMODULENAME=$MODULENAME -DOUTPUTFILE=tmp.trm.tbl
