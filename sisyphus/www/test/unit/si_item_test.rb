require File.dirname(__FILE__) + '/../test_helper'

class SiItemTest < Test::Unit::TestCase
  fixtures :si_items

  def setup
    @si_item = SiItem.find(1)
  end

  # Replace this with your real tests.
  def test_truth
    assert_kind_of SiItem,  @si_item
  end
end
