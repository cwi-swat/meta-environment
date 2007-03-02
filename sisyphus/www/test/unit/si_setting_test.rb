require File.dirname(__FILE__) + '/../test_helper'

class SiSettingTest < Test::Unit::TestCase
  fixtures :si_settings

  def setup
    @si_setting = SiSetting.find(1)
  end

  # Replace this with your real tests.
  def test_truth
    assert_kind_of SiSetting,  @si_setting
  end
end
