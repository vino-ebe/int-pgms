#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

struct dnsCacheValue
{
	vector<string> ip;
	time_t ttl;
};

class dnsCache
{
    private:
        unordered_map<string,dnsCacheValue> m_cacheMap;

    public:
        dnsCache();
        static dnsCache* getSingleton();
        bool cacheLookup(string domainName, bool& ttl);
        bool insertCache(string domainName,dnsCacheValue v);
        bool getCacheItem(string domainName,dnsCacheValue& val);
        void dumpCache();
};

dnsCache::dnsCache()
{
}

dnsCache*
dnsCache::getSingleton()
{
    static dnsCache *cache = new dnsCache();
    return cache;
}

bool
dnsCache::cacheLookup(string domainName, bool& ttl)
{

    if(m_cacheMap.empty())
    {
        return false;
    }
    else
    {
        unordered_map<string,dnsCacheValue>::const_iterator it = m_cacheMap.find(domainName);

        if(it == m_cacheMap.end())
        {
            return false;
        }
        else
        {
            dnsCacheValue val = it->second;
            time_t now;
            if(val.ttl > now)
            {
                ttl = true;
                return true;
            }
            else
            {
                ttl = false;
                return true;
            }
        }
    }
}

bool
dnsCache::insertCache(string domainName,dnsCacheValue v)
{
    time_t now;

    dnsCacheValue val;
    val.ip = v.ip;
    val.ttl = now + (time_t)v.ttl;

    pair<string,dnsCacheValue> element(domainName,val);
    m_cacheMap.insert(element);

    return true;
}

bool
dnsCache::getCacheItem(string domainName,dnsCacheValue& val)
{
    if(m_cacheMap.empty())
    {
        return false;
    }
    else
    {
        unordered_map<string,dnsCacheValue>::const_iterator it = m_cacheMap.find(domainName);

        if(it == m_cacheMap.end())
        {
            return false;
        }
        else
        {
            val = it->second;
            return true;
        }
    }
}

void
dnsCache::dumpCache()
{
    cout<<"Dumping Cache"<<endl;
    dnsCacheValue val;
    unordered_map<string,dnsCacheValue>::const_iterator it;

    if(!m_cacheMap.empty())
    {
        for(it = m_cacheMap.begin(); it != m_cacheMap.end();++it)
        {
            val = it->second;
            cout<<"Domain Name:"<<(it->first).c_str()<<"ip:"<<val.ip[0]<<endl;
        }
    }
}

int main()
{
    cout<<"DNS Cache"<<endl;
    dnsCache *cache = dnsCache::getSingleton();

    dnsCacheValue val;
    val.ip.push_back("20.1.1.1");
    val.ttl = 1211;
    string domain = "www.google.com";

    cache->insertCache(domain,val);

    dnsCacheValue val1;
    val1.ip.push_back("255.1.1.1");
    val1.ttl = 1221;
    domain = "www.yahoo.com";

    cache->insertCache(domain,val1);
    bool ttl;
    if(cache->cacheLookup(domain,ttl))
    {
        cout<<"Look up success"<<"ttl"<<ttl<<endl;
    }
    else
    {
        cout<<"Look up failed"<<endl;
    }

    dnsCacheValue res;
    cache->getCacheItem(domain,res);
    cout<<"Result"<<res.ip[0]<<endl;
    cache->dumpCache();

}
