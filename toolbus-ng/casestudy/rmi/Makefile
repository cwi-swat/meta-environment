CLASSES = \
	AddressBook.class \
	AddressBookImpl.class \
	AddressBookImpl_Stub.class \
	AddressBookServer.class \
	RemoteClient.class

all: $(CLASSES)
	@echo Target \'all\' up-to-date!

AddressBook.class: AddressBook.java
AddressBookImpl.class: AddressBook.java AddressBookImpl.java
RemoteClient.class: AddressBook.java RemoteClient.java
AddressBookServer.class: AddressBookImpl.java AddressBookServer.java

AddressBookImpl_Stub.class: AddressBookImpl.java
	rmic -v1.2 AddressBookImpl


clean:
	rm -f $(CLASSES)

%.class: %.java
	javac $<
