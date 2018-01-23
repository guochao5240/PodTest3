Pod::Spec.new do |s|
s.name     = 'OOReader'
s.version  = '0.0.1'
s.license  = 'MIT'
s.summary  = 'OOReader for iOS7+'
s.homepage = 'https://github.com/guochao5240/'
s.social_media_url = 'https://github.com/azaxas128/MiPushSDK'
s.authors  = { 'zhuge' => '2271637488@qq.com' }
s.source   = { :git => 'https://github.com/guochao5240/PodTest3.git', :tag => s.version, :submodules => true }
s.requires_arc = true

s.ios.deployment_target = '8.0'

s.source_files =  "OOReader/Headers/*.{h,m}","OOReader/**"
#s.vendored_library = 'OOReader.framework'
#s.resources = ["KingReaderSDK/*.bundle"]
s.frameworks = 'SystemConfiguration','CoreTelephony'
#s.libraries = 'xml2', 'z','resolv','sqlite3'
end

