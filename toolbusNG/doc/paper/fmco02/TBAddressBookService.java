import java.util.*;

import aterm.*;
import aterm.pure.*;

public class TBAddressBookService implements AddressBookTif
{
  private static int id = 0;
  private static int createUniqueID() { return id++; }

  private static ATermFactory factory = new PureFactory();

  private Map addressMap;

  public TBAddressBookService() {
    addressMap = new HashMap();
  }

  private AddressBookEntry getEntry(int id) {
    return (AddressBookEntry) addressMap.get(new Integer(id));
  }

  public void deleteEntry(int id) {
    addressMap.remove(new Integer(id));
  }

  public void setName(int id, String name) {
    getEntry(id).setName(name);
  }

  public void setAddress(int id, String address) {
    System.out.println("setAddress: id=" + id + ", address=" + address);
    getEntry(id).setAddress(address);
  }

  public ATerm createEntry() {
    Integer id = new Integer(createUniqueID());
    AddressBookEntry entry = new AddressBookEntry();
    addressMap.put(id, entry);
    return factory.make("snd-value(new-entry(<int>))", id);
  }

  public void recTerminate(ATerm t0) {}

  public static final void main(String[] args) throws Exception {
    TBAddressBookService service = new TBAddressBookService();
    AddressBookBridge bridge = new AddressBookBridge(factory, service);
    bridge.init(args);
    bridge.connect();
    bridge.run();
  }
}
