targets = {
  "ubuntu18.04" => {
    "box" => "ubuntu/bionic64"
  },
}

Vagrant.configure("2") do |config|
  config.vm.provider "virtualbox" do |v|
    v.cpus = 2
    v.memory = 4096
  end
  config.vm.provider "vmware_desktop" do |v|
    v.cpus = 2
    v.memory = 4096
  end
  targets.each do |name, target|
    box = target["box"]
    config.vm.define name do |build|
      build.vm.box = box
      if name.start_with?('ubuntu', 'debian')
        build.vm.provision 'bootstrap', type: 'shell' do |s|
          s.inline = 'sudo apt-get update;'\
                     'sudo apt-get install --yes clang;'
        end
      end
    end
  end
end
