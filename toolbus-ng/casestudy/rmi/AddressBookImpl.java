package casestudy.rmi;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.*;

public class AddressBookImpl extends UnicastRemoteObject implements AddressBook {
  private Map addressMap;

  public AddressBookImpl() throws RemoteException {
    super();
    addressMap = new HashMap();

    Address address = new Address("John Doe");
    address.setStreet("Elmstreet");
    address.setNumber(7);

    addressMap.put("john", address);
    addressMap.put("guest", address);
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
