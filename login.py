# -*- coding: utf-8 -*-
import urllib
import urllib2
import cookielib
import hashlib



hash = hashlib.md5()
username = u'祝露'
password = '888888'
hash.update(password)
md5password = hash.hexdigest()

hosturl = 'http://172.28.18.226:7001/lemis/'
loginurl = 'http://172.28.18.226:7001/lemis/logonAction.do?method=userLogin'

#flag = 1 上午签到（可能是这样）
#flag = 3 上午签退
#flag = 4 下午签到
#flag = 2 下午签退

signoutAfterNoonUrl = 'http://172.28.18.226:7001/lemis/ad01Action!save_ad01.action?flag=4'
#http://172.28.18.226:7001/lemis/logonAction.do;jsessionid=9zSxJctV0CQmvrm2ZtVxnWT8459QttwwK3r30WQvdGbxCfJ5k1xb!-1000312550?method=userLogin
#get cookie
cj = cookielib.CookieJar()
cookie_support = urllib2.HTTPCookieProcessor(cj)
opener = urllib2.build_opener(cookie_support,urllib2.HTTPHandler)
urllib2.install_opener(opener)
h = urllib2.urlopen(hosturl)
cookie = h.info().get('Set-Cookie').split(';')[0]

#get cname
cname = 'c_name=' + urllib.quote(username.encode('utf-8'))
cookie = cookie + '; ' + cname + '; ' + 'c_pass='

#login in
loginData = {
	'bsc011':username.encode('gbk') ,
	'bsc013':md5password,
	'sys001':'2'
	}
loginData = urllib.urlencode(loginData)

request = urllib2.Request(loginurl, loginData)

request.add_header('Cache-Control','max-age=0')
request.add_header('User-Agent','Mozilla/5.0 (Windows NT 6.1; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/40.0.2214.94 Safari/537.36')
request.add_header('Connection','keep-alive')
request.add_header('Cookie',cookie)
request.add_header('Content-length',68)
request.add_header('Content-Type','application/x-www-form-urlencoded')
request.add_header('Host','172.28.18.226:7001')
request.add_header('Origin','http://172.28.18.226:7001')
request.add_header('Referer','http://172.28.18.226:7001/lemis/LogonDialog.jsp')
response = urllib2.urlopen(request)

#cookie = response.info().get('Set-Cookie').split(';')[0]
#
##get cname
#cname = 'c_name=' + urllib.quote(username.encode('utf-8'))
#cookie = cookie + '; ' + cname + '; ' + 'c_pass='


#signout
signoutreq = urllib2.Request(signoutAfterNoonUrl)
signoutreq.add_header('Cookie',cookie)
signoutrs = urllib2.urlopen(signoutreq)
print signoutrs.read()

