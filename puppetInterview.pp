class helloworld {
    notify { 'Hello, Puppet': }
}

ogdmoq

/var/save/puppet_count_4/countfiles_ext_a_p_v.txt

node default{
        file { "/puppet-demo/msrdok.txt":
                content => "hello,world",
                mode => 0644; }
}

ls|awk -F . '{print $NF}'|grep -Eo 'j|p|v'
ls|awk -F . '$NF ~ /j|v|p/ {count++}END{print count}'

ls | awk -F . '$NF ~ /a|v|p/ {count++}END{print count}' > /var/save/puppet_count_4/countfiles_ext_a_p_v.txt

node default{
        exec { "count_files":
		  cwd     => '/var/save/puppet_count_4/files',
		  creates => '/var/save/puppet_count_4/countfiles_ext_a_p_v.txt',
		  path    => ['/usr/bin', '/usr/sbin','/bin',],
		  command    => "ls | awk -F . '$NF ~ /a|v|p/ {count++}END{print count}'",	
		}
}