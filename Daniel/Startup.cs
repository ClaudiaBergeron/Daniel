using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(Daniel.Startup))]
namespace Daniel
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
