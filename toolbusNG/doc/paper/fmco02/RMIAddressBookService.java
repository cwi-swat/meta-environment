import java.rmi.RemoteException;
import java.rmi.server.unicastRemoteObject;
import java.util.*;

public class RMIAddressBookService
  extends UnicastRemoteObject
  implements IAddressBookService
{
  private Map addressMap;

  public RMIAddressBookService() throws RemoteException {
    super();
    addressMap = new HashMap();
  }

  private AddressBookEntry getEntry(int id) {
    return (AddressBookEntry) addressMap.get(new Integer(id));
  }

  public int createAddress() throws RemoteException {
    return 0;
  }

  public void deleteAddress(int id) throws RemoteException {
    addressMap.remove(new Integer(id));
  }

  public void setName(int id, String name) throws RemoteException {
    getEntry(id).set
  }

  public void setAddress(int id, String address) throws RemoteException {
  }

  public void setZip(int id, String zip) throws RemoteException {
  }
}
