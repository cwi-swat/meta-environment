package casestudy;

import java.rmi.RemoteException;
import java.util.Hashtable;

import javax.rmi.PortableRemoteObject;

public class AddressBookImpl extends PortableRemoteObject implements AddressBook {
  private Hashtable addresses;

  public AddressBookImpl() throws RemoteException {
    super();
    addresses = new Hashtable();
    setAddress("hayco", "Balistraat 130II");
    setAddress("pieter", "Ergens anders 42");
  }

  public void setAddress(String name, String address) throws RemoteException {
    addresses.put(name, address);
  }

  public String getAddress(String name) throws RemoteException {
    return (String) addresses.get(name);
  }

}
