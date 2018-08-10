FROM java:8-jre
ADD MemoryEater.class /
ENTRYPOINT ["java", "-Xmx2048M", "-Xms256M", "MemoryEater"]
