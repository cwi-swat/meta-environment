package casestudy.rmi;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.*;

public class AddressBookImpl extends UnicastRemoteObject implements AddressBook {
  private Map addressMap;

  public AddressBookImpl() throws RemoteException {
    super();
    addressMap = new HashMap();

    Address shared = new Address("Balistraat", "130 II");
    add("hayco", shared);
    add("loge", shared);

    add("pieter", new Address("Ergens anders", "42"));
  }

  public void add(String name, Address address) throws RemoteException {
    addressMap.put(name, address);
  }

  public void remove(String name) throws RemoteException {
    addressMap.remove(name);
  }

  public Address getAddress(String name) throws RemoteException {
    return (Address) addressMap.get(name);
  }
}
