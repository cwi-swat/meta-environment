package casestudy.rmi;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.*;

class Address {
  private String street;
  private String number;

  public Address(String street, String number) {
    this.street = street;
    this.number = number;
  }

  public String getStreet() { return street; }
  public String getNumber() { return number; }

  public boolean equals(Object o) {
    if (o instanceof Address) {
      Address peer = (Address) o;
      return peer.getStreet().equals(street)
	&& peer.getNumber().equals(number);
    }
    return false;
  }

  public int hashCode() {
    return (street.hashCode() << 2) ^ number.hashCode();
  }
}

public class AddressBookImpl extends UnicastRemoteObject implements AddressBook {
  private Map addressMap;

  public AddressBookImpl() throws RemoteException {
    super();
    addressMap = new HashMap();

    String shared = new String("Balistraat 130 II");
    add("hayco", shared);
    add("loge", shared);

    add("pieter", "Ergens anders 42");
  }

  public void add(String name, String address) throws RemoteException {
    addressMap.put(name, address);
  }

  public void remove(String name) throws RemoteException {
    addressMap.remove(name);
  }

  public String getAddress(String name) throws RemoteException {
    return (String) addressMap.get(name);
  }
}
