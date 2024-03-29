import { useState , useEffect } from 'react'

import Head from 'next/head'
import styles from '../styles/Home.module.css'
import stylesTrust from '../styles/Trust.module.css'

import Pagination from '../components/paginationTrust'
import { paginate } from './paginate'
import isTrustRoots from '../public/trustStore/trusModel'

const Tablemodels = ({data,name}) => {

    const [posts, setPosts] = useState([])
    useEffect(() =>{
        const getPosts = async () =>{
            //const {data: res} = await axios.get('https://jsonplaceholder.typicode.com/posts')
            setPosts(data)
        }
        getPosts()
    },[])

    //console.log(posts.length)

    const [currentPage,  setCurrentPage] = useState(1);
    const pageSize = 10
    const handlePageChange = (page) => {
        setCurrentPage(page)
    }
    //console.log(useState(1))
    //console.log(currentPage)
    
    const PaginatePosts = paginate(posts, currentPage, pageSize)

    return (
        <div className={styles.container} >
            <Head>
                <title>{name}</title>
                <meta name="description" content="Generated by create next app" />
                <link rel="icon" href="/favicon.ico" />
            </Head>
            <main className={styles.main}>
                <h2 className={styles.title}>
                    Trust Store of {name}
                </h2> 
                <table className='table'>
                    <thead>
                        <tr>
                            <th className={stylesTrust.col_1}>ID</th>
                            <th className={stylesTrust.col_1}>Nro de Serial</th>
                            <th className={stylesTrust.col_1}>Nombres<p className={stylesTrust._p}>Nombre Comun</p></th>
                            <th className={stylesTrust.col_1}>Validez<p className={stylesTrust._p}>Desde-Hasta</p></th>
                            <th className={stylesTrust.col_1}>Llave pública<p className={stylesTrust._p}>Algoritmo-Tamaño</p></th>
                            <th className={stylesTrust.col_1}>Uso de la llave</th>
                            <th className={stylesTrust.col_1}>OID</th>
                            <th className={stylesTrust.col_1}>SHA-1</th>
                        </tr>
                    </thead>
                    <tbody>
                        {
                            PaginatePosts.map((post) => 
                            (
                                <tr key={post.id}>
                                    <td className={stylesTrust.col_2}>{post.id}</td>
                                    <td className={stylesTrust.col_2}>{post.nmSerial}</td>
                                    <td className={stylesTrust.col_2}>{post.issuer}</td>
                                    <td className={stylesTrust.col_2}>{post.validFrom} - {post.validTo}</td>
                                    <td className={stylesTrust.col_2}>{post.asymKey} - {post.nmBits} <p className={stylesTrust._p}>{post.typeKey}</p></td>
                                    <td className={stylesTrust.col_2}>{post.usePublicKey}</td>
                                    <td className={stylesTrust.col_2}>{post.oidPublicKey}</td>
                                    <td className={stylesTrust.col_2}>{post.certSha}</td>                            
                                </tr>        
                            ))
                        }
                        
                    </tbody>
                </table>
                <Pagination items = {posts.length} pageSize = {pageSize} currentPage = {currentPage}  onPageChange = {handlePageChange}/>
            </main>
        

            <footer className={styles.footer}>
            Grupo@4 Unidos
            </footer>

        </div>
    );
};

//se cambio el getstaticprops por getServerSideProps para recibir parametros
export const getServerSideProps = async (context) => {

    console.log(context.query)
    let certificateCiphered = isTrustRoots(context.query.contentPEM);
    let id = 0;

    const data = certificateCiphered.map(async (cert) => {
        
        
        // console.log(cert);
        // console.log(nameIssuer)
        
        id++
        return {
            id: cert.id,
            issuer: cert.issuer,
            nmSerial: cert.nmSerial,
            validFrom: cert.validFrom,
            validTo: cert.validTo,
            certSha: cert.certSha,
            asymKey: cert.asymKey,
            usePublicKey: cert.usePublicKey,
            oidPublicKey: cert.oidPublicKey,
            nmBits: cert.nmBits,
            typeKey: cert.typeKey,
            pubKey: cert.pubKey,
        }
        //certificateDeciphered.push(result)
    });

    
    // const trustDirectory = path.join(process.cwd(),'pages', 'data',context.query.contentPEM + '.json' )
    // fs.writeFileSync(trustDirectory, JSON.stringify(await Promise.all(data)))
    return {
        props: {
            data: await Promise.all(data),
            name: context.query.contentPEM,
        },
    }

};


export default Tablemodels;