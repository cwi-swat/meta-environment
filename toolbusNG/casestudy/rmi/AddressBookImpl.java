package casestudy.rmi;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.*;

public class AddressBookImpl extends UnicastRemoteObject implements AddressBook {
  private Map addressMap;

  public AddressBookImpl() throws RemoteException {
    super();
    addressMap = new HashMap();
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
